#pragma once

#include "GameFactory.h"
#include <memory>
#include <vector>
#include "CollisionSystem.h"


namespace ArcanoidGame
{
	class GameLogic
	{
	public:
		void OnTick();
		bool TryInit();

	private:
		std::unique_ptr <GameFactory> _gameFactory;
		std::unique_ptr <CollisionSystem> _collisionSystem;
		std::vector<GameObject*> _gameObjects;


		GameObject* gm;
		GameObject* gm2;//TODO DELETE
	};
}
