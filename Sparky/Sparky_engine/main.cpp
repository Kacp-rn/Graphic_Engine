#include<iostream>

#include"src/graphics/window.h"
#include"src/graphics/shader.h"
#include"src/maths/maths.h"

#include"src/graphics/buffers/buffer.h"
#include"src/graphics/buffers/indexbuffer.h"
#include"src/graphics/buffers/vertexarray.h"

#include"src/graphics/renderer2d.h"
#include"src/graphics/simple2drenderer.h"

int main()
{
	using namespace sparky;
	using namespace graphics;
	using namespace maths;


	Window window("Sparky!", 960, 540);
	//glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
	

	mat4 ortho = mat4::othographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();

	shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniformMat4("ml_matrix", mat4::translation(vec3(4, 3, 0)));

	   Renderable2D sprite(maths::vec3(5, 5, 0), maths::vec2(4,4), maths::vec4(0.1, 0.5, 0.7, 1), shader);
	   Renderable2D sprite2(maths::vec3(0, 5, 0), maths::vec2(4, 4), maths::vec4(0.3, 0.6, 0.9, 1), shader);
	   Renderable2D sprite3(maths::vec3(0, 0, 0), maths::vec2(4, 4), maths::vec4(0.4, 0.2, 0.8, 1), shader);
	   Renderable2D sprite4(maths::vec3(5, 0, 0), maths::vec2(4, 4), maths::vec4(0.7, 0.3, 0.5, 1), shader);
	   Renderable2D sprite5(maths::vec3(10, 5, 0), maths::vec2(4, 4), maths::vec4(0.9, 0.1, 0.4, 1), shader);
	   Renderable2D sprite6(maths::vec3(10, 0, 0), maths::vec2(4, 4), maths::vec4(0.6, 0.8, 0.2, 1), shader);

	Simple2DRenderer renderer;


	shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));
	//shader.setUniform4f("colour", vec4(0.2f, 0.3f, 0.8f, 1.0f));


		while (!window.closed())
		{
			window.clear();
			double x, y;
			window.getMousePosition(x, y);
			shader.setUniform2f("light_pos", vec2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));

			renderer.submit(&sprite);
			renderer.submit(&sprite2);
			renderer.submit(&sprite3);
			renderer.submit(&sprite4);
			renderer.submit(&sprite5);
			renderer.submit(&sprite6);

			renderer.flush();

			
			window.update();
		}
	return 0;
}