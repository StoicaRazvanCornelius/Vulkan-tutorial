
SOURCES = main.c compute.c
HEADERS = compute.h
TARGET = vulkan_compute

INCLUDES = -I 
LIBS = -L../

$(TARGET): $(SOURCES) $(HEADERS) #it means the targed depends on sources and headers
	gcc -g -O0 $(SOURCES) $(HEADERS) -lvulkan -o $(TARGET) 
