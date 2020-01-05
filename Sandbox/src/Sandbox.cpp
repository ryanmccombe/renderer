#include "Engine.h"

class Sandbox : public Engine::Application
{
public:
	Sandbox()
	{
		
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