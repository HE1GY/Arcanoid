#include "GameLogic.h"

#include "InputManager.h"
#include <iostream>



namespace ArcanoidGame
{

	GameLogic::GameLogic(std::shared_ptr<Window> window)
		:_window(window)
	{
	}

	void GameLogic::OnTick()
	{

		std::cout << "(" << InputManager::MouseX <<"  ,  " << InputManager::MouseY << ")" << std::endl;

		_collisionSystem->CheckAllCollision();
		for(auto& gm : _gameFactory->GameObjects)
		{
			gm->UpdateComponents();
			gm->Draw();
		}
	}



	bool GameLogic::TryInit()
	{
		_collisionSystem = std::make_shared<CollisionSystem>();
		_gameFactory = std::make_unique<GameFactory>(_collisionSystem,_window);
		_levelBuilder = std::make_unique<LevelBuilder>(_gameFactory,_window);

		BlockType layout[] = {
			BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,
			BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,
			BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,
			BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,
			BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,
			BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,
			BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,
			BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,
			BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,
			BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,
			/*BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,
			BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,
			BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,
			BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,
			BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,
			BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,
			BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,
			BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,
			BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,
			BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,*/
		};

		_levelBuilder->Build(layout);
		
		return true;
	}
}