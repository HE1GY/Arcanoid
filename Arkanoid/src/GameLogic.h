#pragma once

#include "Game/GameFactory.h"
#include <memory>
#include <vector>


namespace ArcanoidGame
{
	class GameLogic
	{
	public:
		void OnTick();
		bool TryInit();

	private:
		std::unique_ptr <GameFactory> _gameFactory;
		std::vector<GameObject*> _gameObjects;
	};
}
