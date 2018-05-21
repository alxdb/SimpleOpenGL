//
//  window.hpp
//  SimpleOpenGL
//
//  Created by Alexander Davidson Bryan on 16/01/2018.
//  Copyright © 2018 Alexander Davidson Bryan. All rights reserved.
//

#ifndef window_hpp
#define window_hpp

#define GLFW_INCLUDE_GLCOREARB
#include "GLFW/glfw3.h"

double getTime();

class Window {
	GLFWwindow* windowID;
public:
	Window(const char * name, int width, int height);
	bool shouldClose();
	void update();
	void clear(float r, float g, float b, float alpha);
	~Window();
};

#endif /* window_hpp */
