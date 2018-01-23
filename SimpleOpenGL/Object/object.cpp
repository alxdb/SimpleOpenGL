//
//  object.cpp
//  SimpleOpenGL
//
//  Created by Alexander Davidson Bryan on 16/01/2018.
//  Copyright © 2018 Alexander Davidson Bryan. All rights reserved.
//

#include <iostream>

#include "object.hpp"

Object::Object(Shader& shader) : shader(shader) {
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
}

Object::Object(float* vertices, size_t vertices_size, unsigned int* elements, size_t elements_size, Shader& shader) : Object(shader) {
	this->vertices.data = vertices;
	this->vertices.size = vertices_size/sizeof(float);
	this->elements.data = elements;
	this->elements.size = elements_size/sizeof(unsigned int);
	create();
}

void Object::create() {
	glBindVertexArray(VAO);
	
	bufferData<float>(GL_ARRAY_BUFFER, VBO, vertices.data, vertices.size, GL_STATIC_DRAW);
	bufferData<unsigned int>(GL_ELEMENT_ARRAY_BUFFER, EBO, elements.data, elements.size, GL_STATIC_DRAW);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

void Object::draw() {
	shader.use();
	// shader.setTransform(transform);
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, (int) elements.size, GL_UNSIGNED_INT, 0);
}

template <typename T>
void Object::bufferData(GLenum bufferType, unsigned int handle, T* data, size_t size, GLenum drawType) {
	glBindBuffer(bufferType, handle);
	glBufferData(bufferType, sizeof(T) * size, data, drawType);
}
