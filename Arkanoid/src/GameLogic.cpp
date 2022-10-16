#include "GameLogic.h"
#include "Framework.h"
#include "InputComponent.h"
#include "BallMover.h"

#include "InputManager.h"
#include <iostream>

#include <algorithm>

namespace ArcanoidGame
{

	GameLogic::GameLogic(std::shared_ptr <Window> window)
		:_window(window)
	{
	}

	void GameLogic::OnTick()
	{

		std::cout << "(" << InputManager::MouseX <<"  ,  " << InputManager::MouseY << ")" << std::endl;

		_collisionSystem->CheckAllCollision();
		for(auto& gm : _gameObjects)
		{
			gm->UpdateComponents();
		}

		for(auto& gm: _gameObjects)
		{
			drawSprite(gm->Sprite, std::round(gm->Position.X), std::round(gm->Position.Y));
		}
	}



	bool GameLogic::TryInit()
	{
		_gameFactory = std::make_unique<GameFactory>();
		_collisionSystem = std::make_unique<CollisionSystem>();

		
		gm = _gameFactory->Create("res/data/01-Breakout-Tiles.png");
		_gameObjects.push_back(gm);

		gm->Position.X = 400;
		gm->Position.Y = 400;
		gm->SetSize(300, 100);

		InputComponent* controll = new InputComponent();

		BoxCollider* box = new BoxCollider();
		_collisionSystem->AddBoxCollider(box);

		gm->AddComponent(controll);
		gm->AddComponent(box);
			

		
		gm2 = _gameFactory->Create("res/data/63-Breakout-Tiles.png");
		_gameObjects.push_back(gm2);

		gm2->Position.X = 500;
		gm2->Position.Y = 200;
		gm2->SetSize(100, 100);
		Vector startDirection(1, 1);

		BallMover* ballMover = new BallMover(startDirection,_window);
		ballMover->IsMoving = true;
		ballMover->Speed = 1;

		CirculCollider* circul = new CirculCollider(ballMover);
		_collisionSystem->AddCirculCollider(circul);

		gm2->AddComponent(ballMover);
		gm2->AddComponent(circul);
		

		return true;
	}
}