//
//  object.hpp
//  SimpleOpenGL
//
//  Created by Alexander Davidson Bryan on 16/01/2018.
//  Copyright © 2018 Alexander Davidson Bryan. All rights reserved.
//

#ifndef object_hpp
#define object_hpp

#include "shader.hpp"

#include <vector>
#include <OpenGL/gl3.h>

struct vertex_data {
	float* data;
	size_t size;
};

struct element_data {
	unsigned int* data;
	size_t size;
};

class Object {
public:
	Object(Shader& shader);
	Object(float* vertices, size_t vertices_size, unsigned int* elements, size_t elements_size, Shader& shader);
	template <typename T>
	void bufferData(GLenum bufferType, unsigned int handle, T* data, size_t size, GLenum drawType);
	void create();
	void draw();
protected:
	vertex_data vertices;
	element_data elements;
	Shader& shader;
	
private:
	unsigned int VAO, VBO, EBO;
};

#endif /* object_hpp */
