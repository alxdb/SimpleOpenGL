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

using namespace std;

string readFile(const char * filename) {
	stringstream inStream;
	ifstream fileStream;
	
	fileStream.exceptions(ifstream::failbit | ifstream::badbit);
	try {
		fileStream.open(filename);
		inStream << fileStream.rdbuf();
		fileStream.close();
	} catch(ifstream::failure e) {
		cout << "could not open " << filename << ":\n" << e.what() << endl;
	}

	return inStream.str();
}

void checkShaderError(unsigned int handle, GLenum type) {
	int success = 0;
	char infoLog[512];
	
	glGetShaderiv(handle, type, &success);
	if (!success) {
		glGetShaderInfoLog(handle, 512, NULL, infoLog);
		if (type == GL_LINK_STATUS) {
			cerr << "shader error on link" << endl;
		} else {
			cerr << "shader error" << endl;
		}
		cerr << infoLog << endl;
	}
}

void checkProgramError(unsigned int handle, GLenum type) {
	int success = 0;
	char infoLog[512];
	
	glGetProgramiv(handle, type, &success);
	if (!success) {
		glGetShaderInfoLog(handle, 512, NULL, infoLog);
		if (type == GL_LINK_STATUS) {
			cerr << "shader error on link" << endl;
		} else {
			cerr << "shader error" << endl;
		}
		cerr << infoLog << endl;
	}
}

GLuint compileShader(const GLchar * source, GLenum type) {
	GLuint shaderHandle = glCreateShader(type);
	
	glShaderSource(shaderHandle, 1, &source, NULL);
	glCompileShader(shaderHandle);
	
	checkShaderError(shaderHandle, GL_COMPILE_STATUS);
	
	return shaderHandle;
}

Shader::Shader(const char * vertFilename, const char * fragFilename, glm::mat4 projection) {
	string vertSourceStr = readFile(vertFilename);
	string fragSourceStr = readFile(fragFilename);
	
	GLuint vertShader = compileShader(vertSourceStr.c_str(), GL_VERTEX_SHADER);
	GLuint fragShader = compileShader(fragSourceStr.c_str(), GL_FRAGMENT_SHADER);
	
	handle = glCreateProgram();
	
	glAttachShader(handle, vertShader);
	glAttachShader(handle, fragShader);
	
	glLinkProgram(handle);
	
	glDeleteShader(vertShader);
	glDeleteShader(fragShader);
	
	checkProgramError(handle, GL_LINK_STATUS);
	
	viewLoc = glGetUniformLocation(handle, "view");
	projLoc = glGetUniformLocation(handle, "projection");
	modelLoc = glGetUniformLocation(handle, "model");
	
	glUseProgram(handle);
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
	this->projection = projection;
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
