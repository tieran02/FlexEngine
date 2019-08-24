#include "flpch.h"
#include "Flex/LayerStack.h"

namespace Flex {
	LayerStack::LayerStack()
	{
		m_layerInsert = m_layers.begin();
	}


	LayerStack::~LayerStack()
	{
		for (ILayer* layer : m_layers)
		{
			delete layer;
		}
	}

	void LayerStack::PushLayer(ILayer* layer)
	{
		m_layerInsert = m_layers.emplace(m_layerInsert, layer);
	}

	void LayerStack::PushOverlay(ILayer* layer)
	{
		m_layers.emplace_back(layer);
	}

	void LayerStack::PopLayer(ILayer* layer)
	{
		auto it = std::find(m_layers.begin(), m_layers.end(), layer);
		if(it != m_layers.end())
		{
			m_layers.erase(it);
			--m_layerInsert;
		}
	}

	void LayerStack::PopOverlay(ILayer* layer)
	{
		auto it = std::find(m_layers.begin(), m_layers.end(), layer);
		if (it != m_layers.end())
		{
			m_layers.erase(it);
		}
	}
}
