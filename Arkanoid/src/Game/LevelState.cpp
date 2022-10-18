#include "LevelState.h"

namespace ArcanoidGame
{
	LevelState::LevelState(LevelBuilder* levelBuilder,GameFactory* gF):
		_gF(gF), _levelBuilder(levelBuilder), AbilitySpawner(nullptr), _activeBlock(0), _startActiveBlock(0)
	{
	}
	void LevelState::OnDeath(GameObject* gameObject)
	{
		_activeBlock--;
		_blockForAbilitySpawn--;

		if(_blockForAbilitySpawn<=0)
		{
			_blockForAbilitySpawn = 10;
			GameObject* gm = AbilitySpawner->GetAbility();
			gm->Position = Vector(gameObject->Position.X, gameObject->Position.Y);
		}

		if(_activeBlock <= 0)
		{
			Restart();
		}
	}
	void LevelState::Restart()
	{
		_levelBuilder->ResetBlocks();
		AbilitySpawner->Restart();
		_activeBlock = _startActiveBlock;
	}

	void  LevelState::SetStartActiveBlock(int count)
	{
		AbilitySpawner->Spawn(count/10);
		_startActiveBlock = count;
		_activeBlock = count;
	}
}