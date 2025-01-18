#include "compute.h"
#include "device.h"
#include "instance.h"
#include "pipeline.h"
#include "memory.h"
#include <stdio.h>

uint32_t InputData[1000];
float OutputData[1000];  

int main(int argc, char **argv)
{
    CreateInstance();
    GetPhysicalDevice();
    CreateDeviceAndComputeQueue();
    CreatePipeline();
    CreateDescriptorSet();
    CreateBuffers(sizeof(InputData), sizeof(OutputData));
    CreateCommandPool();
    PrepareCommandBuffer();

    for(uint32_t i=0; i<1000; i++){
        InputData[i] = i;
        OutputData[i] = 0;
    }

    CopyToInputBuffer(InputData, sizeof(InputData));

    Compute();

    CopyFromOutputBuffer(OutputData, sizeof(OutputData));

    for(uint32_t i=0; i<1000; i++) printf( " InpuData[%d] = %d, OutputData[%d] = %f\n", i, InputData[i], i, OutputData[i]);
    
    DestroyPipeline();
    DestroyCommandPoolAndLogicalDevice();
    
    return 0;
}