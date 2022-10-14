#include "InputManager.h"
#include <iostream>

#include "Utility.h"



namespace ArcanoidGame
{
	void InputManager::OnMouseMove(int x, int y, int xrelative, int yrelative)
	{
		
	}
	void InputManager::OnMouseButtonClick(FRMouseButton button, bool isReleased)
	{
		if(isReleased)
		{
			std::cout << button <<" Released" << std::endl;
		}
		else
		{
			std::cout << button << std::endl;
		}
	}
	void InputManager::OnKeyPressed(FRKey k)
	{
		std::cout << k << std::endl;
	}
	void InputManager::OnKeyReleased(FRKey k)
	{
		std::cout << k <<" Released" << std::endl;
	}
}