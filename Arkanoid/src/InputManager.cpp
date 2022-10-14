#include "InputManager.h"




namespace ArcanoidGame
{
	void InputManager::OnMouseMove(int x, int y, int xrelative, int yrelative)
	{
		MouseX = x;
		MouseY = y;
		MouseXRel = xrelative;
		MouseYRel = yrelative;
	}
	void InputManager::OnMouseButtonClick(FRMouseButton button, bool isReleased)
	{
		if(!isReleased)
		{
			MouseSwitch(button, true);
		}
		{
			MouseSwitch(button, false);
		}
	}
	void InputManager::OnKeyPressed(FRKey k)
	{
		KeySwitch(k, true);
	}
	void InputManager::OnKeyReleased(FRKey k)
	{
		KeySwitch(k, false);
		
	}

	void InputManager::MouseSwitch(FRMouseButton button, bool press)
	{
		switch(button)
		{
			case FRMouseButton::LEFT:
				MLeft = press;
				break;
			case FRMouseButton::MIDDLE:
				MMiddle = press;
				break;
			case FRMouseButton::RIGHT:
				MRight = press;
				break;
			case FRMouseButton::COUNT:
				MCount = press;
				break;
			default:
				break;
		}
	}

	void InputManager::KeySwitch(FRKey k, bool press)
	{
		switch(k)
		{
			case FRKey::RIGHT:
				KRight = press;
				break;
			case FRKey::LEFT:
				KLeft = press;
				break;
			case FRKey::DOWN:
				KDown = press;
				break;
			case FRKey::UP:
				KUp = press;
				break;
			case FRKey::COUNT:
				KCount = press;
				break;
			default:
				break;
		}
	}

}