#include "compute.h"
#include "instance.h"
#include "device.h"
#include "pipeline.h"
#include "memory.h"
#include <stdio.h>
#include <time.h>
#include  <string.h>

uint32_t InputData[1000];
uint32_t OutputData[1000][1000];

uint32_t getTimeStamp()
{
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
}

void generate()
{
    for (uint32_t row = 0; row < 1000; row++)
    {
        for (uint32_t col = 0; col < 1000; col++)
        {
            float r = (float)row / 500.0 - 1.0;
            float i = (float)col / 500.0 - 1.0;

            uint32_t cnt = 0;
            while (((r * r + i * i) < 4.0) && (cnt < 63))
            {
                float temp = r * r - i * i + 0.17;
                i = 2 * r * i + 0.57;
                r = temp;
                cnt++;
            }
            OutputData[row][col] = (cnt << 10) | 0xff000000;
        }
    }
}

int main(int ac, char **av)
{
    CreateInstance();
    GetPhysicalDevice();
    CreateDeviceAndComputeQueue();
    CreatePipeline();
    CreateDescriptorSet();
    CreateBuffers(sizeof(InputData), sizeof(OutputData));
    CreateCommandPool();
    PrepareCommandBuffer();
    CopyToInputBuffer(InputData, sizeof(InputData));

    uint32_t time = getTimeStamp();
    generate();
    time = getTimeStamp() - time;
    printf("CPU fractal: %u ms.\n", time);

    FILE *f = fopen("fractal_cpu.raw", "wb");
    fwrite(OutputData, sizeof(OutputData), 1, f);
    fclose(f);

    memset(OutputData, 0, sizeof(OutputData));    
    time = getTimeStamp();
    Compute();
//    CopyFromOutputBuffer(OutputData, sizeof(OutputData));
    time = getTimeStamp() - time;
    printf("GPU fractal: %u ms.\n", time);

    CopyFromOutputBuffer(OutputData, sizeof(OutputData));

    f = fopen("fractal_gpu.raw", "wb");
    fwrite(OutputData, sizeof(OutputData), 1, f);
    fclose(f);

    DestroyPipeline();
    DestroyCommandPoolAndLogicalDevice();

    return 0;
}
