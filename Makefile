
HEADERS = compute.h device.h instance.h pipeline.h
SOURCES = main.c compute.c device.c instance.c pipeline.c
TARGET = vulkan_compute 

INCLUDES = -I 
LIBS = -L../

SHADER_SRC = shader.comp
SHADER_BIN = comp.spv

$(TARGET): $(SOURCES) $(HEADERS) $(SHADER_BIN) #it means the targed depends on sources and headers
	gcc -g -O0 $(SOURCES) $(HEADERS) -lvulkan -o $(TARGET) 

$(SHADER_BIN): $(SHADER_SRC)
	glslangValidator -V $(SHADER_SRC) -o $(SHADER_BIN)
