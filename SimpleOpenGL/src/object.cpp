#include "object.hpp"

Object::Object(Shader& shader) : shader(shader) {
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
}

void Object::create() {
	TEX = 0;
	glBindVertexArray(VAO);

	bufferData<float>(GL_ARRAY_BUFFER, VBO, vertices.data, vertices.size, GL_STATIC_DRAW);
	bufferData<unsigned int>(GL_ELEMENT_ARRAY_BUFFER, EBO, elements.data, elements.size, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

void Object::create(Texture& texture) {
	TEX = texture.getHandle();
	glBindVertexArray(VAO);

	bufferData<float>(GL_ARRAY_BUFFER, VBO, vertices.data, vertices.size, GL_STATIC_DRAW);
	bufferData<unsigned int>(GL_ELEMENT_ARRAY_BUFFER, EBO, elements.data, elements.size, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	model = glm::mat4(1.0);
}

void Object::draw() {
	shader.use();
	glUniformMatrix4fv(shader.modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	glBindVertexArray(VAO);
	glBindTexture(GL_TEXTURE_2D, TEX);
	glDrawElements(GL_TRIANGLES, (int) elements.size, GL_UNSIGNED_INT, 0);
}

void Object::rotate(float angle, glm::vec3 vec) {
	model = glm::rotate(model, glm::radians(angle), vec);
}

void Object::translate(glm::vec3 vec) {
	model = glm::translate(model, vec);
}

void Object::rotateAbs(float angle, glm::vec3 vec) {
	model = glm::rotate(glm::mat4(1.0), glm::radians(angle), vec);
}

void Object::translateAbs(glm::vec3 vec) {
	model = glm::translate(glm::mat4(1.0), vec);
}

template <typename T>
void Object::bufferData(GLenum bufferType, unsigned int handle, T* data, size_t size, GLenum drawType) {
	glBindBuffer(bufferType, handle);
	glBufferData(bufferType, sizeof(T) * size, data, drawType);
}
