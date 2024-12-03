#pragma once

#include<iostream>
#include<GL/glew.h>
#include<GLFW/glfw3.h>

namespace sparky {namespace graphics {
	class Window
	{
	private:
		const char* m_Title;
		int m_Width, m_Height;
		GLFWwindow* m_Window;
		bool m_Closed;
	public:
		Window(const char* title, int width, int height);
		~Window();
		void update();
		bool closed() const;
		void clear() const;

		inline int getWidth() const { return m_Width; }
		inline int getHeight() const { return m_Height; }
	private:
		bool init();

	

	};



}}