#pragma once
#include "Flex/Core.h"

namespace Flex {
	class Event;
	class Layer
	{
	public:
		FLEX_API Layer(std::string&& name = "Layer") : m_debugName(name) {}
		FLEX_API virtual ~Layer() = default;

		FLEX_API virtual void OnAttach() = 0;
		FLEX_API virtual void OnDetach() = 0;
		FLEX_API virtual void OnUpdate() = 0;
		FLEX_API virtual void OnEvent(Event& event) = 0;

		FLEX_API inline const std::string& GetName() const { return m_debugName; }
	protected:
		std::string m_debugName;
	};
}
