#include <vulkan/vulkan.h>


void CreateDeviceAndComputeQueue(void);
void CreateCommandPool(void);
void CreateDescriptorPool(void);
void DestroyCommandPoolAndLogicalDevice(void);

extern VkDevice LogicalDevice;
extern VkQueue ComputingQueue;
extern VkCommandPool ComputeCmdPool;
extern VkDescriptorPool DescriptorPool;