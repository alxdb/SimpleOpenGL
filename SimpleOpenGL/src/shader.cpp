//
//  shader.cpp
//  SimpleOpenGL
//
//  Created by Alexander Davidson Bryan on 16/01/2018.
//  Copyright © 2018 Alexander Davidson Bryan. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <OpenGL/gl3.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "shader.hpp"
#include "Shaders/basic.fs.h"
#include "Shaders/basic.vs.h"

void checkShaderError(unsigned int handle, GLenum type) {
	int success = 0;
	char infoLog[512];

	if (type == GL_LINK_STATUS) {
		glGetProgramiv(handle, type, &success);
	} else {
		glGetShaderiv(handle, type, &success);
	}
	if (!success) {
		glGetShaderInfoLog(handle, 512, NULL, infoLog);
		if (type == GL_LINK_STATUS) {
			std::cerr << "shader error on link" << std::endl;
		} else {
			std::cerr << "shader error" << std::endl;
		}
		std::cerr << infoLog << std::endl;
	}
}

GLuint compileShader(const GLchar * source, GLenum type) {
	GLuint shaderHandle = glCreateShader(type);

	glShaderSource(shaderHandle, 1, &source, NULL);
	glCompileShader(shaderHandle);

	checkShaderError(shaderHandle, GL_COMPILE_STATUS);

	return shaderHandle;
}

Shader::Shader(glm::mat4 projection) : projection(projection) {
	std::string vertSourceStr(SimpleOpenGL_res_Shaders_basic_vs_glsl, SimpleOpenGL_res_Shaders_basic_vs_glsl_len); 
	std::string fragSourceStr(SimpleOpenGL_res_Shaders_basic_fs_glsl, SimpleOpenGL_res_Shaders_basic_fs_glsl_len); 

	GLuint vertShader = compileShader(vertSourceStr.c_str(), GL_VERTEX_SHADER);
	GLuint fragShader = compileShader(fragSourceStr.c_str(), GL_FRAGMENT_SHADER);

	handle = glCreateProgram();

	glAttachShader(handle, vertShader);
	glAttachShader(handle, fragShader);

	glLinkProgram(handle);

	glDeleteShader(vertShader);
	glDeleteShader(fragShader);

	checkShaderError(handle, GL_LINK_STATUS);

	viewLoc = glGetUniformLocation(handle, "view");
	projLoc = glGetUniformLocation(handle, "projection");
	modelLoc = glGetUniformLocation(handle, "model");

	glUseProgram(handle);
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
}

void Shader::setView() {
	glUseProgram(handle);
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
}

void Shader::translateView(glm::vec3 vec) {
	view = glm::translate(view, vec);
	setView();
}

void Shader::rotateView(float angle, glm::vec3 vec) {
	view = glm::rotate(view, glm::radians(angle), vec);
	setView();
}

void Shader::use() {
	glUseProgram(handle);
}
