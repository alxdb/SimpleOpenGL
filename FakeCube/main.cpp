#include <iostream>
#include <vector>

#include "SimpleOpenGL.hpp"

int width = 600;
int height = 600;

//mat4 projection = perspective(glm::radians(45.0f), (float) width / (float) height, 0.1f, 100.0f);
glm::mat4 projection = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, 0.1f, 100.0f);

int main() {
	Window window("SimpleOpenGL", width, height);
	Shader shader(projection);

	std::vector<Rect> fakeCube;

	for (int i = 0; i < 6; i++) {
		float r = 0.6f * (float) i / 6.0;
		float g = fmod(1.1 + r, 0.4) + 0.5;
		float b = abs(fmod(g - 1.0, 1.0));
		std::cout << r << "_" << g << "_" << b << std::endl;
		Rect rect = Rect({r, g, b}, shader);

		if (i > 1) {
			rect.rotate(90.0f, glm::vec3(0.0f, 1.0f, 0.0f));
		}

		if (i > 3) {
			rect.rotate(90.0f, glm::vec3(1.0f, 0.0f, 0.0f));
		}

		if (i % 2 == 0) {
			rect.translate(glm::vec3(0.0f, 0.0f, 0.5f));
		} else {
			rect.translate(glm::vec3(0.0f, 0.0f, -0.5f));
		}

		fakeCube.push_back(rect);
	}

	shader.translateView(glm::vec3(0.0f, 0.0f, -2.0f));
	shader.rotateView(-45.0f, glm::vec3(.0f, 1.0f, 0.0f));
	shader.rotateView(45.0f, glm::vec3(1.0f, 0.0f, -1.0f));

	while(!window.shouldClose()) {
		window.clear(0.1, 0.2, 0.6, 1.0);

		double time = getTime();

		for (int i = 0; i < 4; i++) {
			fakeCube[i].rotate(0.2f, glm::vec3(0.0, 1.0, 0.2));
		}

		for (int i = 4; i < 6; i++) {
			fakeCube[i].rotate(0.2f, glm::vec3(0.5, 1.0, 0.0));
		}

		for (Rect& rect : fakeCube) {
			rect.translate(glm::vec3(0.0, sin(time + M_PI_2) * 1e-2, 0.0));
		}

		for (Rect& rect : fakeCube) {
			rect.draw();
		}

		window.update();
	}
	return 0;
}
