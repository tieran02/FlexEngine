#pragma once
#include "Flex/Core.h"

namespace Flex {
	class Event;
	class Layer
	{
	public:
		FLEX_API Layer(const std::string& name = "Layer");
		FLEX_API virtual ~Layer();

		FLEX_API virtual void OnAttach() {}
		FLEX_API virtual void OnDetach() {}
		FLEX_API virtual void OnUpdate() {}
		FLEX_API virtual void OnEvent(Event& event) {}

		FLEX_API inline const std::string& GetName() const { return m_debugName; }
	protected:
		std::string m_debugName;
	};
}
