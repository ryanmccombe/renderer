#pragma once
#include <cstdio>
#include "Log.h"

#ifdef ENGINE_PLATFORM_WINDOWS

extern Engine::Application* Engine::CreateApplication();

int main(int argc, char** argv)
{
	Engine::Log::Init();
	ENGINE_CORE_INFO("Initialised Engine");
	ENGINE_CORE_INFO("Initialised Logger");
	ENGINE_INFO("Initialised Logger");
	
	auto app = Engine::CreateApplication();
	app->Run();

	delete app;
}
#endif
