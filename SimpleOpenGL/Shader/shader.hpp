//
//  shader.hpp
//  SimpleOpenGL
//
//  Created by Alexander Davidson Bryan on 16/01/2018.
//  Copyright © 2018 Alexander Davidson Bryan. All rights reserved.
//

#ifndef shader_hpp
#define shader_hpp

class Shader {
	unsigned int handle;
public:
	Shader(const char * vertexFilename, const char * fragmentFilename);
	void use();
};

#endif /* shader_hpp */
