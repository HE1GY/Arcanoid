#pragma once
#include "GameObject.h"

namespace ArcanoidGame
{
	class GameFactory
	{
	public:
		GameObject* Create(const char* path);
	};
}
