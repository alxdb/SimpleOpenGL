//
//  triangle.hpp
//  SimpleOpenGL
//
//  Created by Alexander Davidson Bryan on 23/01/2018.
//  Copyright © 2018 Alexander Davidson Bryan. All rights reserved.
//

#ifndef triangle_hpp
#define triangle_hpp

#include "SimpleOpenGL.hpp"

class Triangle : public Object {
public:
	Triangle(point, point, point, Shader&);
	Triangle(pos, pos, pos, col, Shader&);
	~Triangle();
};

#endif /* triangle_hpp */
