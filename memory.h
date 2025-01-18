#include <vulkan/vulkan.h>

void CreateBuffers(uint32_t inputSize, uint32_t outputsize);
void DestroyBuffers(void);
void CopyToInputBuffer(void *data, uint32_t size);
void CopyFromOutputBuffer(void *data, uint32_t size);