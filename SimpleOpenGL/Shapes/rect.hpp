//
//  rect.hpp
//  SimpleOpenGL
//
//  Created by Alexander Davidson Bryan on 23/01/2018.
//  Copyright © 2018 Alexander Davidson Bryan. All rights reserved.
//

#ifndef rect_hpp
#define rect_hpp

#include "SimpleOpenGL.hpp"

class Rect : public Object {
public:
	Rect(pos, pos, col, Shader&);
	Rect(pos, pos, col, col, col, col, Shader&);
	~Rect();
};

#endif /* rect_hpp */
