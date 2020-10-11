#include "Engine.h"

class TestLayer : public Engine::Layer
{
public:
	TestLayer() : Layer("Test") {}
	void OnUpdate() override
	{
		// ENGINE_INFO("Test Layer Updated");
		if (Engine::Input::IsKeyPressed(ENGINE_KEY_SPACE))
		{
			ENGINE_INFO("Space Bar Pressed");
		}
	};

	void OnEvent(Engine::Event& event) override
	{
		if (event.GetEventType() == Engine::EventType::KeyPressed)
		{
			Engine::KeyPressedEvent& e = (Engine::KeyPressedEvent&)event;
			ENGINE_TRACE("Key Pressed Event: {0} ({1})", e.GetKeyCode(), (char)e.GetKeyCode());
		}
	}
};

class Sandbox : public Engine::Application
{
public:
	Sandbox()
	{
		PushLayer(new TestLayer());
		PushOverlay(new Engine::ImGuiLayer());

	}
	~Sandbox()
	{
		
	}
};

Engine::Application* Engine::CreateApplication()
{
	ENGINE_INFO("Initialised Sandbox");
	return new Sandbox();
}