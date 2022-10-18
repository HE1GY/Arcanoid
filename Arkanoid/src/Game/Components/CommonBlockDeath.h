#pragma once
#include "CollisionEvent.h."
#include "ICollider.h"

namespace ArcanoidGame
{
	class DeathEventListener;

	class CommonBlockDeath :public IComponent, public CollisionEvent
	{
	public:
		  void OnCollision(ICollider& other, Vector& contactPoint) override;
		 void Update()override;
		 std::vector<DeathEventListener*> DeathListeners;
	};
}