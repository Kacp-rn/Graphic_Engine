#include<iostream>

#include"src/graphics/window.h"

int main()
{
	using namespace sparky;
	using namespace graphics;

	Window window("Sparky!", 960, 540);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glClearColor(0.270588f, 0.392157f, 0.0705882f, 1.0f);

		while (!window.closed())
		{
			std::cout << window.getWidth() << ", " << window.getHeight() << std::endl;

			window.clear();
			/*glBegin(GL_TRIANGLES);
			glVertex2f(-0.5f, -0.5f);
			glVertex2f(0.0f, 0.5f);
			glVertex2f(0.5f, -0.5f);
			glEnd();*/

			glDrawArrays(GL_ARRAY_BUFFER, 0, 0);
			window.update();
		}
	return 0;
}