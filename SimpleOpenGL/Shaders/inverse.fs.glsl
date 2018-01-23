#version 410
out vec4 FragColor;

in vec4 vertexColor;

void main() {
	FragColor = vec4(1.0 - vertexColor.x, 1.0 - vertexColor.y, 1.0 - vertexColor.z, vertexColor.w);
}
