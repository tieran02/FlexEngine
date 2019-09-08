#pragma once
#include "Flex/Core.h"

namespace Flex {
	class Event;
	class ILayer
	{
	public:
	    ILayer(std::string&& name = "ILayer") : m_debugName(name) {}
		virtual ~ILayer() = default;

		FLEX_API virtual void OnAttach() = 0;
		FLEX_API virtual void OnDetach() = 0;
		FLEX_API virtual void OnUpdate() = 0;
		FLEX_API virtual void OnEvent(Event& event) = 0;

		const char* GetName() const { return m_debugName.c_str(); }
	protected:
		std::string m_debugName;
	};
}
