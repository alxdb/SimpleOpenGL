//
//  triangle.cpp
//  SimpleOpenGL
//
//  Created by Alexander Davidson Bryan on 23/01/2018.
//  Copyright © 2018 Alexander Davidson Bryan. All rights reserved.
//

#include "shapes.hpp"

Triangle::Triangle(point a, point b, point c, Shader& shader) : Object(shader) {
	vertices.size = 3 * 6;
	vertices.data = new float[vertices.size] {
		a.pos.x, a.pos.y, 0.0, a.col.r, a.col.g, a.col.b,
		b.pos.x, b.pos.y, 0.0, b.col.r, b.col.g, b.col.b,
		c.pos.x, c.pos.y, 0.0, c.col.r, c.col.g, c.col.b,
	};
	
	elements.size = 3;
	elements.data = new unsigned int[elements.size] {
		0, 1, 2
	};
	
	create();
}

Triangle::Triangle(pos a, pos b, pos c, col colour, Shader& shader) : Object(shader) {
	vertices.size = 3 * 6;
	vertices.data = new float[vertices.size] {
		a.x, a.y, 0.0, colour.r, colour.g, colour.b,
		b.x, b.y, 0.0, colour.r, colour.g, colour.b,
		c.x, c.y, 0.0, colour.r, colour.g, colour.b,
	};
	
	elements.size = 3;
	elements.data = new unsigned int[elements.size] {
		0, 1, 2
	};
	
	create();
}

Triangle::~Triangle() {
	delete vertices.data;
	delete elements.data;
}
