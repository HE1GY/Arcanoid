#include "GameLogic.h"
#include "Framework.h"

namespace ArcanoidGame
{

	GameLogic::GameLogic(InputManager* input):
		_input(input)
	{
	}

	void GameLogic::OnTick()
	{



		for(auto& gms: _gameObjects)
		{
			GameObject* gm = gms;
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
		_gameObjects.push_back(gm);

		return true;
	}
}