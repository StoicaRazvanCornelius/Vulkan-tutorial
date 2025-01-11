#include <vulkan/vulkan.h>
#include <stdio.h>
VkCommandBuffer CommandBuffer = VK_NULL_HANDLE;


void PrepareCommandBuffer(void){
    VkCommandBufferAllocateInfo allocInfo;
    memset(&allocInfo, 0, sizeof(allocInfo));
    allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFOl;
    allocInfo.commandPool = CommandPool;
    allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    allocInfo.commandBufferCount = 1;

    if(vkAllocateCommandBuffers(LogicalDevice, &allocInfo, &CommandBuffer) != VK_SUCCESS)
    {
        printf("Failed to allocate the buffer\n")
        return;
    }

    VkCommandBufferBeginInfo beginInfo;
    memset(&beginInfo, 0, sizeof(beginInfo));
    beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    beginInfo.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;

    if(vkBeginCommandBuffer(CommandBuffer, &beginInfo))
    {
        printf("Failed to begin the buffer \n");
        return;    
    }

    vkCmdDispatch(CommandBuffer, 1, 1, 1);

    if(vkEndCommandBuffer(CommandBuffer) !=VK_SUCCESS){
        printf("Faild to end the buffer \n");
        return;
    }

}
int Compute(void){
    
    VkSubmitInfo submitInfo;
    memset(&submitInfo, 0, sizeof(submitInfo));
    submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    submitInfo.commandBufferCount = 1;
    submitInfo.pCommandBuffers = &CommandBuffer;


    if( vkQueueSubmit(ComputingQueue, 1, &submitInfo, NULL) != VK_SUCCESS)
    {
        printf("submitting the command buffer failed\n");
        return -1;
    }
        
    return 0;
}
