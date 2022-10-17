#pragma once
#include "CollisionEvent.h."
#include "ICollider.h"

namespace ArcanoidGame
{
	class CommonBlockDeath :public IComponent, public CollisionEvent
	{
		  void OnCollision(ICollider& other, Vector& contactPoint) override;
		 void Update()override;
	};
}