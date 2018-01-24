//
//  object.hpp
//  SimpleOpenGL
//
//  Created by Alexander Davidson Bryan on 16/01/2018.
//  Copyright © 2018 Alexander Davidson Bryan. All rights reserved.
//

#ifndef object_hpp
#define object_hpp

#include <OpenGL/gl3.h>

#include "shader.hpp"
#include "texture.hpp"

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
	// Constructors
	Object(Shader&);
	Object(float*, size_t, unsigned int*, size_t, Shader&);
	// Methods
	template <typename T>
	void bufferData(GLenum, unsigned int, T*, size_t, GLenum);
	void create();
	void create(Texture&);
	void draw();
protected:
	vertex_data vertices;
	element_data elements;
	Shader& shader;
	
private:
	unsigned int VAO, VBO, EBO, TEX;
};

#endif /* object_hpp */
