#include "enginepch.h"
#include "Application.h"

// TODO: delete this test code
#include <GLFW/glfw3.h>

namespace Engine
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
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

	void Application::OnEvent(Event& e)
	{
		ENGINE_CORE_INFO("{0}", e);
	}
}
