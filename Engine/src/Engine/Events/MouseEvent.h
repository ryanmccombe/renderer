#pragma once

#include "Event.h"

#include <sstream>

namespace Engine
{
	class ENGINE_API MouseMovedEvent : public Event
	{
	public:
		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

		MouseMovedEvent(float x, float y) : m_MouseX(x), m_MouseY(y)
		{
		}

		float GetX() const { return m_MouseX; }
		float GetY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << GetX() << ", " << GetY();
			return ss.str();
		}

	private:
		float m_MouseX, m_MouseY;
	};

	class ENGINE_API MouseScrolledEvent : public Event
	{
	public:
		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

		MouseScrolledEvent(float xOffset, float yOffset) : m_xOffset(xOffset), m_yOffset(yOffset)
		{
		}

		float GetXOffset() const { return m_xOffset; }
		float GetYOffset() const { return m_yOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
			return ss.str();
		}

	private:
		float m_xOffset, m_yOffset;
	};

	class ENGINE_API MouseButtonEvent : public Event
	{
	public:
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
		int GetMouseButton() const { return m_Button; }
	protected:
		MouseButtonEvent(int button) : m_Button(button)
		{
		}

		int m_Button;
	};

	class ENGINE_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		EVENT_CLASS_TYPE(MouseButtonPressed)
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button)
		{
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << GetMouseButton();
			return ss.str();
		}
	};

	class ENGINE_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		EVENT_CLASS_TYPE(MouseButtonReleased)
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button)
		{
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << GetMouseButton();
			return ss.str();
		}
	};
}
