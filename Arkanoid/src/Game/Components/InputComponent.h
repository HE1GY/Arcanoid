#pragma once
#include "IComponent.h"


namespace ArcanoidGame
{
	class InputComponent :public IComponent
	{
	public:
		void Update()override;
	};
}