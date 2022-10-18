#include "AbilitySpawner.h"
#include <stdlib.h> 

namespace ArcanoidGame
{
	AbilitySpawner::AbilitySpawner(GameFactory* gameFactory):
		_gameFactory(gameFactory)
	{
		srand(time(NULL));
	}
	void  AbilitySpawner::Spawn(int count)
	{
		for(size_t i = 0; i < count; i++)
		{
			int spawner = rand() % 2;
			GameObject* ability;
			if(spawner == 0)
			{
				ability = _gameFactory->CreateDecreasesAbility();
			}
			else
			{
				ability = _gameFactory->CreateEncresesAbility();
			}
			ability->Enable = false;
			_spawnedAbilities.push_back(ability);
		}
	}


	GameObject* AbilitySpawner::GetAbility()
	{
		int index = rand() % _spawnedAbilities.size();
		GameObject* gm= _spawnedAbilities[index];
		gm->Enable = true;
		return gm;
	}

	void AbilitySpawner::Restart()
	{
		for(auto& ability : _spawnedAbilities)
		{
			ability->Enable = false;
		}
	}
}