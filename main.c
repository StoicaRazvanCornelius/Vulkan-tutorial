#include "compute.h"
#include "device.h"
#include "instance.h"
#include "pipeline.h"
#include "memory.h"

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

    Compute();

    DestroyPipeline();
    DestroyCommandPoolAndLogicalDevice();
    
    return 0;
}