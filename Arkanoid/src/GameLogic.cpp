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

		/*std::cout << "(" << InputManager::MouseX <<"  ,  " << InputManager::MouseY << ")" << std::endl;*/

		_collisionSystem->CheckAllCollision();


		for(auto& gm : _gameFactory->GameObjects)
		{
			gm->Draw();
			gm->UpdateComponents();
		}
	}



	bool GameLogic::TryInit()
	{
		_collisionSystem = std::make_shared<CollisionSystem>();
		_gameFactory = std::make_shared<GameFactory>(_collisionSystem,_window);
		_levelBuilder = std::make_shared<LevelBuilder>(_gameFactory,_window);
		_levelState = std::make_shared<LevelState>(_levelBuilder.get(), _gameFactory.get());
		_levelState->AbilitySpawner = new AbilitySpawner(_gameFactory.get());
		_gameFactory->LevelState = _levelState.get();
		
		BlockType layout[] = {
			BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,
			BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,
			BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,
			BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,
			BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,
			BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,
			BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,
			BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,
			BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,BlockType::Explosion,
			BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,BlockType::Common,
			
		};
		_levelBuilder->Build(layout);
		_levelState->SetStartActiveBlock(_levelBuilder->BuiltBlock);
		return true;
	}
}