//
//  window.cpp
//  SimpleOpenGL
//
//  Created by Alexander Davidson Bryan on 16/01/2018.
//  Copyright © 2018 Alexander Davidson Bryan. All rights reserved.
//

#include <iostream>

#include "window.hpp"

void error_callback(int error, const char * description) {
	std::cerr << "Error: " << description << std::endl;
}

Window::Window(const char * name, int width, int height) {
	glfwSetErrorCallback(error_callback);
	
	if (!glfwInit()) exit(EXIT_FAILURE);
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); //required for macOS
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	windowID = glfwCreateWindow(width, height, name, NULL, NULL);
	
	if (!windowID) {
		glfwTerminate();
		std::cerr << "Failed to create GLFW window" << std::endl;
		exit(EXIT_FAILURE);
	};
	
	std::cout << "Window " << windowID << " created" << std::endl;
	glfwMakeContextCurrent(windowID);
	
	glEnable(GL_DEPTH_TEST);
}

Window::~Window() {
	glfwTerminate();
	std::cout << "Window " << windowID << " destroyed" << std::endl;
}

void Window::update() {
	glfwSwapBuffers(windowID);
	glfwPollEvents();
}

bool Window::shouldClose() {
	return glfwWindowShouldClose(windowID);
}

void Window::clear(float r, float g, float b, float alpha) {
	glClearColor(r, g, b, alpha);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

double getTime() {
	return glfwGetTime();
}
