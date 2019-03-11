#pragma once
#include "hmpch.h"
#include "Hammer/Core.h"

namespace Hammer {

	class HM_API Input
	{
	public:
		inline static bool IsKeyPressed(int keycode) { return  s_Intance->IsKeyPressedImpl(keycode); }
		inline static bool IsMouseButtonPressed(int button) { return s_Intance->IsMouseButtonPressedImpl(button);}
		inline static std::pair<float, float> GetMousePosition() { return s_Intance->GetMousePositionImpl(); }
		inline static float GetMouseXPos() { return s_Intance->GetMouseXPosImpl(); }
		inline static float GetMousYPos() { return s_Intance->GetMousYPosImpl(); }
	protected:
		inline virtual bool IsKeyPressedImpl(int keycode)const = 0;
		inline virtual bool IsMouseButtonPressedImpl(int button)const = 0;
		inline virtual std::pair<float, float> GetMousePositionImpl()const = 0;
		inline virtual float GetMouseXPosImpl()const = 0;
		inline virtual float GetMousYPosImpl()const = 0;
	private:
		static Input* s_Intance;
	};
}