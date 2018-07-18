#ifndef object_hpp
#define object_hpp

// #include <OpenGL/gl3.h>
#include "OGL.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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
	// Object(float*, size_t, unsigned int*, size_t, Shader&);
	void draw();
	void rotate(float angle, glm::vec3 vec);
	void translate(glm::vec3 vec);
	void rotateAbs(float angle, glm::vec3 vec);
	void translateAbs(glm::vec3 vec);
protected:
	Object(Shader&);
	void create();
	void create(Texture&);
	vertex_data vertices;
	element_data elements;
private:
	unsigned int VAO, VBO, EBO, TEX;
	Shader& shader;
	glm::mat4 model = glm::mat4(1.0);
	template <typename T>
	void bufferData(GLenum, unsigned int, T*, size_t, GLenum);
};

#endif
