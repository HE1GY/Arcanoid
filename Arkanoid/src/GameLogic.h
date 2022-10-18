#pragma once

#include "CollisionSystem.h"
#include <memory>
#include <vector>
#include "GameFactory.h"
#include "LevelBuilder.h"
#include "LevelState.h"


namespace ArcanoidGame
{
	class GameLogic
	{
	public:
		GameLogic(std::shared_ptr<Window> window);
		void OnTick();
		bool TryInit();

	private:
		std::shared_ptr<GameFactory> _gameFactory;
		std::shared_ptr<CollisionSystem> _collisionSystem;
		std::shared_ptr<Window> _window;
		std::shared_ptr<LevelBuilder> _levelBuilder;
		std::shared_ptr<LevelState> _levelState;
	};
}
