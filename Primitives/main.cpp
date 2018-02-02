 //
//  main.cpp
//  SimpleOpenGL
//
//  Created by Alexander Davidson Bryan on 16/01/2018.
//  Copyright © 2018 Alexander Davidson Bryan. All rights reserved.
//

#include <iostream>

#include "SimpleOpenGL.hpp"

using std::cout, std::endl;

int width = 600;
int height = 600;

glm::mat4 perspective = glm::perspective(glm::radians(45.0f), (float) width / (float) height, 0.1f, 100.0f);
glm::mat4 ortho = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, 0.1f, 100.0f);

int main() {
	Window window("SimpleOpenGL", width, height);
	Shader shader("basic.vs.glsl", "basic.fs.glsl", ortho);

	Texture arrow("arrow.png");
	Texture water("water.jpg");
	
	Triangle triangle({1.0, 1.0, 1.0}, shader, water);
	Rect rect1({1.0, 0.0, 0.0}, shader, arrow);
	Rect rect2({0.0, 1.0, 0.0}, shader, arrow);
	Rect rect3({0.0, 0.0, 1.0}, shader, arrow);
	
	shader.translateView(glm::vec3(0.0f, 0.0f, -2.0f));
	shader.rotateView(-45.0f, glm::vec3(.0f, 1.0f, 0.0f));
	shader.rotateView(45.0f, glm::vec3(1.0f, 0.0f, -1.0f));
	
	
	rect2.rotate(90.0f, glm::vec3(1.0, 0.0, 0.0));
	rect3.rotate(90.0f, glm::vec3(0.0, 1.0, 0.0));
	
	while(!window.shouldClose()) {
		window.clear(0.8, 0.8, 0.8, 1.0);
		
		rect1.draw();
		rect2.draw();
		rect3.draw();
		rect1.rotateAbs(20.0f, glm::vec3(0.0, 1.0, 0.0));
		rect2.rotate(0.2f, glm::vec3(0.0, 1.0, 0.0));
		rect3.rotate(0.2f, glm::vec3(0.0, 1.0, 0.0));
		triangle.draw();
		triangle.rotate(5.0f, glm::vec3(1.0, 0.0, 0.0));

//		cout << glfwGetTime() << endl;
		
		window.update();
	}
	
	return 0;
}
