 //
//  main.cpp
//  SimpleOpenGL
//
//  Created by Alexander Davidson Bryan on 16/01/2018.
//  Copyright © 2018 Alexander Davidson Bryan. All rights reserved.
//

#include <iostream>
#include <OpenGL/gl3.h>

#include "window.hpp"
#include "SimpleOpenGL.hpp"

using std::cout, std::endl;

int main() {
	Window window("SimpleOpenGL", 600, 600);
	Shader basic("basic.vs.glsl", "basic.fs.glsl");
	
	Texture arrow("arrow.png");
	Texture water("water.jpg");
	
	Triangle triangle({-0.5, -0.5}, {0.0,  0.5}, {0.5, -0.5}, {1.0, 1.0, 1.0}, basic, water);
	Rect rect({-0.5, 0.5}, {0.5, -0.5}, {0.7, 0.2, 0.3}, basic, arrow);
	
	while(!window.shouldClose()) {
		window.clear(0.8, 0.8, 0.8, 1.0);
		
		rect.draw();
		triangle.draw();
		
		cout << glfwGetTime() << endl;
		
		window.update();
	}
	
	return 0;
}
