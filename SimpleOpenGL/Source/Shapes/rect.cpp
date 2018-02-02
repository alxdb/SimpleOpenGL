//
//  square.cpp
//  SimpleOpenGL
//
//  Created by Alexander Davidson Bryan on 23/01/2018.
//  Copyright © 2018 Alexander Davidson Bryan. All rights reserved.
//

#include "shapes.hpp"

// 	Rect rect1({-0.5, 0.5}, {0.5, -0.5}, {1.0, 0.0, 0.0}, shader, arrow);

Rect::Rect(col colour, Shader& shader) : Object(shader) {
	vertices.size = 4 * 6;
	vertices.data = new float[vertices.size] {
		-0.5,  0.5, 0.0, colour.r, colour.g, colour.b,
		 0.5,  0.5, 0.0, colour.r, colour.g, colour.b,
		-0.5, -0.5, 0.0, colour.r, colour.g, colour.b,
		 0.5, -0.5, 0.0, colour.r, colour.g, colour.b
	};
	
	elements.size = 6;
	elements.data = new unsigned int[elements.size] {
		0, 1, 2,
		1, 2, 3
	};
	
	create();
	
	delete vertices.data;
	delete elements.data;
}

Rect::Rect(col colour, Shader& shader, Texture& texture) : Object(shader) {
	vertices.size = 4 * 8;
	vertices.data = new float[vertices.size] {
		-0.5,  0.5, 0.0, colour.r, colour.g, colour.b, 0.0, 1.0,
		 0.5,  0.5, 0.0, colour.r, colour.g, colour.b, 1.0, 1.0,
		-0.5, -0.5, 0.0, colour.r, colour.g, colour.b, 0.0, 0.0,
		 0.5, -0.5, 0.0, colour.r, colour.g, colour.b, 1.0, 0.0
	};
	
	elements.size = 6;
	elements.data = new unsigned int[elements.size] {
		0, 1, 2,
		1, 2, 3
	};
	
	create(texture);
	
	delete vertices.data;
	delete elements.data;
}

