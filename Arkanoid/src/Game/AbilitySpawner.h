#pragma once
#include "GameFactory.h"

namespace ArcanoidGame
{
	class AbilitySpawner
	{
	public:
		AbilitySpawner(GameFactory* gameFactory);
		void Spawn(int count);
		GameObject* GetAbility();
		void Restart();
	private:
		GameFactory*  _gameFactory;
		std::vector<GameObject*> _spawnedAbilities;
	};
}