#pragma once
#include "CollisionEvent.h"
#include "BallSizeModifier.h"
#include "ModifierEvent.h"
#include "GameObject.h"

namespace ArcanoidGame
{
	class AbilityReceiver:public IComponent, public CollisionEvent
	{
	public:
		void Update()override;
		void OnCollision(ICollider& other, Vector& contactPoint) override;
		ModifierEvent* ModifierEventListener;
	};
}