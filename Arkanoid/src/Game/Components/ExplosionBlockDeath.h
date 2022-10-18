#pragma once
#include "CollisionEvent.h"
#include "DeathEvent.h"
#include "GameFactory.h"

namespace ArcanoidGame
{
	class ExplosionBlockDeath:public IComponent,public CollisionEvent
	{
	public:
		ExplosionBlockDeath(GameFactory* gameFactory);
		void OnCollision(ICollider& other, Vector& contactPoint) override;
		void Update()override;
		std::vector<DeathEventListener*> DeathListeners;
	private:
		GameFactory* _gameFactory;
		GameObject* _explosionBall;
		int _frameDelayForExplosion;
		ICollider* _killer;
	};
}