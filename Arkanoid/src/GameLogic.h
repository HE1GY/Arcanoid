#pragma once

#include "Game/GameFactory.h"
#include <memory>
#include <vector>
#include "InputManager.h"

namespace ArcanoidGame
{
	class GameLogic
	{
	public:
		GameLogic(InputManager* input);
		void OnTick();
		bool TryInit();

	private:
		std::unique_ptr <GameFactory> _gameFactory;
		std::vector<GameObject*> _gameObjects;
		InputManager* _input;
	};
}
