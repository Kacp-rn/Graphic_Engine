#include<iostream>

#include"src/graphics/window.h"
#include"src/maths/vec2.h"

int main()
{
	using namespace sparky;
	using namespace graphics;

	Window window("Sparky!", 960, 540);

	
	glClearColor(0.270588f, 0.392157f, 0.0705882f, 1.0f);
	
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	sparky::maths::vec2 a(1.0f, 2.0f);

		while (!window.closed())
		{
			//std::cout << window.getWidth() << ", " << window.getHeight() << std::endl;

			window.clear();

			double x, y;
			window.getMousePosition(x, y);
			std::cout << x << ", " << y << std::endl;

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