#include "Engine.h"

class TestLayer : public Engine::Layer
{
public:
	TestLayer() : Layer("Test") {}
	void OnUpdate() override
	{
		ENGINE_INFO("Test Layer Updated");
	};

	void OnEvent(Engine::Event& event) override
	{
		ENGINE_TRACE("{0}", event);
	}
};

class Sandbox : public Engine::Application
{
public:
	Sandbox()
	{
		PushLayer(new TestLayer());

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