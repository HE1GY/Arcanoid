#include "GameLogic.h"
#include "Framework.h"
#include "InputComponent.h"
#include "BallMover.h"

#include "InputManager.h"
#include <iostream>

#include <algorithm>

namespace ArcanoidGame
{

	void GameLogic::OnTick()
	{

		std::cout << "(" << InputManager::MouseX <<"  ,  " << InputManager::MouseY << ")" << std::endl;

		/*int w;
		int h;
		gm->GetSize(w, h);

		int clX = std::clamp(gm2->Position.X, gm->Position.X , gm->Position.X + 2*w);
		int clY = std::clamp(gm2->Position.Y, gm->Position.Y, gm->Position.Y + 2*h);

		int dist = Vector::Magnitude(gm2->Position, *(new Vector(clX,clY)));;

		gm2->GetSize(w, h);

		if(h  > dist)
		{
			w++;
		}*/

		_collisionSystem->CheckAllCollision();

		for(auto& gm : _gameObjects)
		{
			gm->UpdateComponents();
		}

		for(auto& gm: _gameObjects)
		{
			drawSprite(gm->Sprite, gm->Position.X, gm->Position.Y);
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
		gm2->Position.Y = 100;
		gm2->SetSize(100, 100);
		Vector startVelocity(0, 1);

		BallMover* ballMover = new BallMover(startVelocity);
		ballMover->IsMoving = true;
		ballMover->Speed = 1;

		CirculCollider* circul = new CirculCollider();
		_collisionSystem->AddCirculCollider(circul);

		gm2->AddComponent(ballMover);
		gm2->AddComponent(circul);
		

		return true;
	}
}