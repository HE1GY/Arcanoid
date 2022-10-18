#pragma once
#include "GameObject.h"
#include "CollisionSystem.h"
#include "PlatformInput.h"
#include "Window.h"
#include "DeathEvent.h"
#include "AbilityReceiver.h"

namespace ArcanoidGame
{
	class GameFactory
	{
	public:

		GameObject* MoverBall;
		inline static GameObject* PlatformGO;

		DeathEventListener* LevelState;
		std::vector<GameObject*> GameObjects;

		GameFactory(std::shared_ptr <CollisionSystem> collisionSys, std::shared_ptr <Window> window);
		GameObject* CreatePlatform();
		GameObject* CreateBall();
		GameObject* CreateCommonBlock();
		GameObject* CreateExplosionBlock();
		GameObject* CreateExplosion();
		GameObject* CreateEncresesAbility();
		GameObject* CreateDecreasesAbility();
		int GetScaledSize(const int& defaultWindowValue, const int& currentWindowValue, const int& defautValue);

	private:
		std::shared_ptr <CollisionSystem> _collisionSys;
		std::shared_ptr <Window>_window;
		void RegisterGameObject(GameObject* gameObject);
		
		AbilityReceiver* _abilityReceiver;
	};
}
