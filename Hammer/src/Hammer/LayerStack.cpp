#include "hmpch.h"
#include "LayerStack.h"
namespace Hammer {



	LayerStack::LayerStack()
	{
		HM_CORE_TRACER
		m_LayerInsert = m_Layers.begin();
	}

	LayerStack::~LayerStack()
	{
		HM_CORE_TRACER
		for (Layer* layer : m_Layers)
			delete layer;
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		HM_CORE_TRACER
		m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
	}

	void LayerStack::PushOverlay(Layer* overlay)
	{
		HM_CORE_TRACER
		m_Layers.emplace_back(overlay);
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		HM_CORE_TRACER
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
			m_LayerInsert--;
		}
	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		HM_CORE_TRACER
		auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
		if (it != m_Layers.end())
			m_Layers.erase(it);
	}
}