#include "PlatformInput.h"
#include "InputManager.h"
#include "GameObject.h"

namespace ArcanoidGame
{
	PlatformInput::PlatformInput(std::shared_ptr<Window> window)
		:_window(window)
	{
	}


	void PlatformInput::Update()
	{
		if(InputManager::KRight && Parent->Position.X+ Parent->Size.X < _window->Width)
		{
			Parent->Position.X += _speed;
		}
		if(InputManager::KLeft && Parent->Position.X > 0)
		{
			Parent->Position.X -= _speed;
		}
	}

}