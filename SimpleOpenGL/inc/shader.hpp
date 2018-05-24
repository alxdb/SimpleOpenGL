//
//  shader.hpp
//  SimpleOpenGL
//
//  Created by Alexander Davidson Bryan on 16/01/2018.
//  Copyright © 2018 Alexander Davidson Bryan. All rights reserved.
//

#ifndef shader_hpp
#define shader_hpp

#include <glm/glm.hpp>

class Shader {
	unsigned int handle;
public:
	Shader(glm::mat4 projection);
	void use();
	void setView();
	void translateView(glm::vec3);
	void rotateView(float, glm::vec3);
	unsigned int viewLoc;
	unsigned int projLoc;
	unsigned int modelLoc;
	glm::mat4 projection;
	glm::mat4 view = glm::mat4(1.0);
};
#endif /* shader_hpp */
