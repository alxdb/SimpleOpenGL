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
		cerr << "shader error" << endl;
		cerr << infoLog << endl;
	}
}

void checkProgramError(unsigned int handle) {
	int success = 0;
	char infoLog[512];
	
	glGetProgramiv(handle, GL_LINK_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(handle, 512, NULL, infoLog);
		cerr << "Program error" << endl;
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

Shader::Shader(const char * vertFilename, const char * fragFilename) {
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
	
	checkProgramError(handle);
}

void Shader::use() {
	glUseProgram(handle);
}
