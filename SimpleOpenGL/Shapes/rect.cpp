//
//  square.cpp
//  SimpleOpenGL
//
//  Created by Alexander Davidson Bryan on 23/01/2018.
//  Copyright © 2018 Alexander Davidson Bryan. All rights reserved.
//

#include "shapes.hpp"

//float sqvertices[] = {
//	-0.5, -0.5, 0.0, 1.0, 0.0, 0.0,
//	-0.5,  0.5, 0.0, 0.0, 1.0, 0.0,
//	0.5, -0.5, 0.0, 0.0, 1.0, 0.0,
//	0.5,  0.5, 0.0, 0.0, 0.0, 1.0,
//};
//
//unsigned int sqindices[] = {
//	0, 1, 3,
//	3, 2, 0
//};

Rect::Rect(pos nw, pos se, col colour, Shader& shader) : Object(shader) {
	vertices.size = 4 * 6;
	vertices.data = new float[vertices.size] {
		nw.x, nw.y, 0.0, colour.r, colour.g, colour.b,
		se.x, nw.y, 0.0, colour.r, colour.g, colour.b,
		nw.x, se.y, 0.0, colour.r, colour.g, colour.b,
		se.x, se.y, 0.0, colour.r, colour.g, colour.b
	};
	
	elements.size = 6;
	elements.data = new unsigned int[elements.size] {
		0, 1, 2,
		1, 2, 3
	};
	
	create();
};

Rect::~Rect() {
	delete vertices.data;
	delete elements.data;
}
