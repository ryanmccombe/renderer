#include "enginepch.h"
#include "Application.h"

// TODO: delete this test code
#include <GLFW/glfw3.h>

namespace Engine
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}
	
	Application::~Application()
	{
		
	}
	
	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();

			// TODO: delete this test code
			glClearColor(0.15f, 0.15f, 0.15f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
		};
	}
}