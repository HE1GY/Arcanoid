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
		void OnKeyReleased(FRKey k);;
	};
}

