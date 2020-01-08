#include "enginepch.h"

#include "WindowsWindow.h"

#include "Engine/Events/MouseEvent.h"
#include "Engine/Events/KeyEvent.h"
#include "Engine/Events/ApplicationEvent.h"

namespace Engine
{
	static bool s_GLFWInitialised = false;

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}
	
	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		glfwSwapInterval(enabled ? 1 : 0);

		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		ENGINE_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialised)
		{
			int success = glfwInit();
			ENGINE_CORE_ASSERT(success, "Could not initialise GLFW");

			s_GLFWInitialised = true;
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		// TODO implement other glfw callbacks too
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
			data.Width = width;
			data.Height = height;
			WindowResizeEvent event(width, height);
			data.EventCallback(event);
		});
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}
}
