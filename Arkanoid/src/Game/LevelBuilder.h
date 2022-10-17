#pragma once
#include "GameFactory.h"
#include <memory>
#include "BlockType.h"

namespace ArcanoidGame
{
	class LevelBuilder
	{
	public:
		LevelBuilder(std::shared_ptr<GameFactory> gameFactory, std::shared_ptr <Window>window);
		void Build(BlockType blocksLayout[]);
	private:
		std::shared_ptr<GameFactory> _gameFactory;
		std::shared_ptr<Window> _window;
		GameObject* CreateByType(BlockType type);
	};
}