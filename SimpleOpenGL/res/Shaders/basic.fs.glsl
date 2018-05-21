#version 410
out vec4 FragColor;

in vec4 col;
in vec2 tex;

uniform sampler2D Texture;

void main() {
	if (textureSize(Texture, 1).x == 0) {
		FragColor = col;
	} else {
		FragColor = texture(Texture, tex) * col;
	}
}
