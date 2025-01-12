
SOURCES = main.c compute.c device.c instance.c
HEADERS = compute.h device.h instance.h 
TARGET = vulkan_compute 

INCLUDES = -I 
LIBS = -L../

$(TARGET): $(SOURCES) $(HEADERS) #it means the targed depends on sources and headers
	gcc -g -O0 $(SOURCES) $(HEADERS) -lvulkan -o $(TARGET) 
