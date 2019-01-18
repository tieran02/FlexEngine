#pragma once
#include "Core.h"
#include "Layer.h"

namespace Flex
{
	class LayerStack
	{
	public:
		FLEX_API LayerStack();
		FLEX_API ~LayerStack();

		FLEX_API void PushLayer(Layer* layer);
		FLEX_API void PushOverlay(Layer* layer);
		FLEX_API void PopLayer(Layer* layer);
		FLEX_API void PopOverlay(Layer* layer);

		FLEX_API std::vector<Layer*>::iterator begin() { return m_layers.begin(); }
		FLEX_API std::vector<Layer*>::iterator end() { return m_layers.end(); }
	private:
		std::vector<Layer*> m_layers;
		std::vector<Layer*>::iterator m_layerInsert;
	};
}
