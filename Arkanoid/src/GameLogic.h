#pragma once

#include "GameFactory.h"
#include <memory>
#include <vector>
#include "CollisionSystem.h"
#include "Window.h"


namespace ArcanoidGame
{
	class GameLogic
	{
	public:
		GameLogic(std::shared_ptr <Window> window);
		void OnTick();
		bool TryInit();

	private:
		std::unique_ptr <GameFactory> _gameFactory;
		std::unique_ptr <CollisionSystem> _collisionSystem;
		std::vector<GameObject*> _gameObjects;
		std::shared_ptr	<Window> _window;


		GameObject* gm;
		GameObject* gm2;//TODO DELETE
	};
}
