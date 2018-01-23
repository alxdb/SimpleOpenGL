#version 410
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aCol;

out vec4 vertexColor;
uniform mat4 transform;

void main() {
	gl_Position = vec4(aPos, 1.0);
	vertexColor = vec4(aCol, 1.0);
}
