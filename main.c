#include "compute.h"
#include "device.h"
#include "instance.h"
#include "pipeline.h"

int main(int argc, char **argv)
{
    CreateInstance();
    GetPhysicalDevice();
    CreateDeviceAndComputeQueue();
    CreatePipeline();
    CreateDescriptorSet();
    CreateCommandPool();
    PrepareCommandBuffer();
    Compute();  
    DestroyPipeline();
    DestroyCommandPoolAndLogicalDevice();
    
    return 0;
}