#include "GameLogic.h"
#include "Framework.h"
#include "InputComponent.h"

namespace ArcanoidGame
{

	void GameLogic::OnTick()
	{
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

		GameObject* gm = _gameFactory->Create("D:/dev/Arkanoid/Arkanoid/res/data/01-Breakout-Tiles.png");
		gm->Position.X=400;
		gm->Position.Y=400;
		gm->SetSize(300, 100);
		InputComponent* a = new InputComponent();
		gm->AddComponent(a);
		_gameObjects.push_back(gm);

		GameObject* gm2 = _gameFactory->Create("D:/dev/Arkanoid/Arkanoid/res/data/01-Breakout-Tiles.png");
		gm2->Position.X = 100;
		gm2->Position.Y = 200;
		gm2->SetSize(300, 100);
		InputComponent* a2 = new InputComponent();
		gm2->AddComponent(a2);
		_gameObjects.push_back(gm2);

		return true;
	}
}