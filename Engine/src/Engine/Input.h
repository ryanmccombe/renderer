#pragma once

#include "Engine/Core.h"

namespace Engine
{
	class ENGINE_API Input
	{
	public:
		static bool IsKeyPressed(int keycode) { return s_Instace->IsKeyPressedImpl(keycode); }
		static bool IsMouseButtonPressed(int button) { return s_Instace->IsMouseButtonPressedImpl(button); }
		static std::pair<float, float> GetMousePosition() { return s_Instace->GetMousePositionImpl(); }
		static float GetMouseX() { return s_Instace->GetMouseXImpl(); }
		static float GetMouseY() { return s_Instace->GetMouseYImpl(); }
	protected:
		virtual bool IsKeyPressedImpl(int keycode) = 0;
		virtual bool IsMouseButtonPressedImpl(int keycode) = 0;
		virtual std::pair<float, float> GetMousePositionImpl() = 0;
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;
	private:
		static Input* s_Instace;
	};
}