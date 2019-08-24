#pragma once
#include "Flex/Core.h"

namespace Flex {
	class Event;
	class ILayer
	{
	public:
		FLEX_API ILayer(std::string&& name = "ILayer") : m_debugName(name) {}
		FLEX_API virtual ~ILayer() = default;

		FLEX_API virtual void OnAttach() = 0;
		FLEX_API virtual void OnDetach() = 0;
		FLEX_API virtual void OnUpdate() = 0;
		FLEX_API virtual void OnEvent(Event& event) = 0;

		FLEX_API inline const std::string& GetName() const { return m_debugName; }
	protected:
		std::string m_debugName;
	};
}
