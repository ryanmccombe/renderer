#pragma once

#include "Core.h"
#include "Window.h"
#include "Engine/LayerStack.h"
#include "Events/Event.h"
#include "Engine/Events/ApplicationEvent.h"

#include "Engine/ImGui/ImGuiLayer.h"

namespace Engine
{
	class ENGINE_API Application {
	public:
		Application();
		virtual ~Application();
		void Run();
		void OnEvent(Event& e);
		void PushLayer(Layer* Layer);
		void PushOverlay(Layer* Layer);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; };
		
	private:
        bool OnWindowClose(WindowCloseEvent& e);
                
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		static Application* s_Instance;
	};

	// To be defined in client
	Application* CreateApplication();
}
