#pragma once
#include "Core.h"
#include "ILayer.h"

namespace Flex
{
	class LayerStack
	{
	public:
		FLEX_API LayerStack();
		FLEX_API ~LayerStack();

		FLEX_API void PushLayer(ILayer* layer);
		FLEX_API void PushOverlay(ILayer* layer);
		FLEX_API void PopLayer(ILayer* layer);
		FLEX_API void PopOverlay(ILayer* layer);

		FLEX_API std::vector<ILayer*>::iterator begin() { return m_layers.begin(); }
		FLEX_API std::vector<ILayer*>::iterator end() { return m_layers.end(); }
	private:
		std::vector<ILayer*> m_layers;
		std::vector<ILayer*>::iterator m_layerInsert;
	};
}
