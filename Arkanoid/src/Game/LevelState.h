#pragma once
#include"AbilitySpawner.h"
#include "DeathEvent.h"
#include <vector>

#include "LevelBuilder.h"

namespace ArcanoidGame
{
	class LevelState:public DeathEventListener
	{
	public:
		LevelState(LevelBuilder* levelBuilder, GameFactory* gF);
		void OnDeath(GameObject* gameObject)override;
		AbilitySpawner* AbilitySpawner;
		void SetStartActiveBlock(int count);
	private:
		int _startActiveBlock;
		int _activeBlock;
		int _blockForAbilitySpawn=10;
		void Restart();
		LevelBuilder* _levelBuilder;
		GameFactory* _gF;
	};
}