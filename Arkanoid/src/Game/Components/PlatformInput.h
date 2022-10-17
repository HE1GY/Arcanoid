#pragma once
#include "IComponent.h"
#include <memory>
#include "Window.h"

namespace ArcanoidGame
{
	class PlatformInput :public IComponent
	{
	public:
		PlatformInput(std::shared_ptr <Window>window);
		void Update()override;
	private:
		const float _speed=2;
		std::shared_ptr <Window>_window;
	};
}