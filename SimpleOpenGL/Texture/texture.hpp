//
//  texture.hpp
//  SimpleOpenGL
//
//  Created by Alexander Davidson Bryan on 24/01/2018.
//  Copyright © 2018 Alexander Davidson Bryan. All rights reserved.
//

#ifndef texture_hpp
#define texture_hpp

#include <OpenGL/gl3.h>

#include "stb_image.h"

class Texture {
	unsigned int handle;
public:
	Texture(const char*);
	unsigned int getHandle() { return handle; };
};

#endif /* texture_hpp */
