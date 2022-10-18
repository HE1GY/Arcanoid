#include "LevelBuilder.h"

namespace ArcanoidGame
{
	LevelBuilder::LevelBuilder(std::shared_ptr<GameFactory> gameFactory, std::shared_ptr <Window>window)
		:_gameFactory(gameFactory),_window(window),BuiltBlock(0)
	{
	}

	void LevelBuilder::Build(BlockType blocksLayout[])
	{
		GameObject* platform = _gameFactory->CreatePlatform();
		platform->Position = Vector(_window->Width / 2 - platform->Size.X / 2,_window->Height - platform->Size.Y);

		GameObject* ball = _gameFactory->CreateBall();
		ball->Position = Vector(_window->Width / 2 - ball->Size.X / 2, _window->Height - platform->Size.Y- ball->Size.Y);

		int horizontalSpace=_gameFactory->GetScaledSize(Window::DefaultWidth,_window->Width,3);
		int VerticalSpace= _gameFactory->GetScaledSize(Window::DefaultHeight, _window->Width, 3);
		for(size_t y = 0; y < 10; y++)
		{
			for(size_t x = 0; x < 12; x++)
			{
				GameObject* Block = CreateByType(blocksLayout[y*12+x]);
				if(Block == nullptr)
				{
					continue;
				}
				BuiltBlock++;
				_blocks.push_back(Block);
				Block->Position.X = 15+x * (Block->Size.X + horizontalSpace);
				Block->Position.Y = y * (Block->Size.Y + VerticalSpace);
			}
		}
	}

	GameObject* LevelBuilder::CreateByType(BlockType type)
	{
		GameObject* block;
		switch(type)
		{
			case ArcanoidGame::None:
				block = nullptr;
				break;
			case ArcanoidGame::Common:
				block = _gameFactory->CreateCommonBlock();
				break;
			case ArcanoidGame::Explosion:
				block = _gameFactory->CreateExplosionBlock();
				break;
			default:
				block = nullptr;
				break;
		}
		return block;
	}


	void LevelBuilder::ResetBlocks()
	{
		for(size_t i = 0; i < _blocks.size(); i++)
		{
			_blocks[i]->Enable = true;
		}
	}
}