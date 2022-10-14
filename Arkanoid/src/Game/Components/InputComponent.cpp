#include "InputComponent.h"

namespace ArcanoidGame
{
	void InputComponent::Update()
	{
		if(InputManager::KRight)
		{
			Parent->Position.X += 1;
		}
		if(InputManager::KLeft)
		{
			Parent->Position.X -= 1;
		}
		if(InputManager::KUp)
		{
			Parent->Position.Y -= 1;
		}
		if(InputManager::KDown)
		{
			Parent->Position.Y += 1;
		}
	}

}