//
//  shapes.hpp
//  SimpleOpenGL
//
//  Created by Alexander Davidson Bryan on 23/01/2018.
//  Copyright © 2018 Alexander Davidson Bryan. All rights reserved.
//

#ifndef shapes_h
#define shapes_h

struct pos {
	float x;
	float y;
};

struct col {
	float r;
	float g;
	float b;
};

struct point {
	pos pos;
	col col;
};

#include "triangle.hpp"
#include "rect.hpp"

#endif /* shapes_h */
