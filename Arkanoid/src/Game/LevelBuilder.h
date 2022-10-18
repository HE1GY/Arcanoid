#pragma once
#include "GameFactory.h"
#include <memory>
#include "BlockType.h"
#include <vector>

namespace ArcanoidGame
{
	class LevelBuilder
	{
	public:
		LevelBuilder(std::shared_ptr<GameFactory> gameFactory, std::shared_ptr <Window>window);
		void Build(BlockType blocksLayout[]);
		void ResetBlocks();
		int BuiltBlock;
	private:
		std::shared_ptr<GameFactory> _gameFactory;
		std::shared_ptr<Window> _window;
		GameObject* CreateByType(BlockType type);
		std::vector<GameObject*> _blocks;
	};
}