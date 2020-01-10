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

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
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
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		ENGINE_CORE_TRACE("{0}", e);
	}
}
