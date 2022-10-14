#pragma once
#include "Framework.h"

namespace ArcanoidGame
{

	class InputManager
	{
	public:
		void OnMouseMove(int x, int y, int xrelative, int yrelative);
		void OnMouseButtonClick(FRMouseButton button, bool isReleased);
		void OnKeyPressed(FRKey k);
		void OnKeyReleased(FRKey k);

		inline static int MouseX, MouseY, MouseXRel, MouseYRel;
		inline static bool KRight,KLeft,KDown,KUp,KCount;
		inline static bool MLeft,MMiddle,MRight,MCount;

	private:
		void KeySwitch(FRKey k, bool press);
		void MouseSwitch(FRMouseButton button, bool press);
	};
}

