#pragma once
#include "Engine/Layer.h"

namespace Engine
{
	class ENGINE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnUpdate();
		void OnEvent(Event& event);
		void OnAttach() override;
		void OnDetach() override;
	private:
		float m_Time = 0.0f;
	};
}
