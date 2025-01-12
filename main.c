#include "compute.h"
#include "device.h"
#include "instance.h"

int main(int argc, char **argv)
{
    CreateInstance();
    GetPhysicalDevice();
    CreateDeviceAndComputeQueue();
    CreateCommandPool();
    PrepareCommandBuffer();
    Compute();  
    DestroyCommandPoolAndLogicalDevice();
    
    return 0;
}