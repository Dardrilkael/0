#include "hmpch.h"
#include "Layer.h"

namespace Hammer {
	
	Layer::Layer(const std::string& debugName)
		:m_DebugName(debugName)
	{
		HM_CORE_TRACER
	}

	Layer::~Layer()
	{
		HM_CORE_TRACER
	}


}