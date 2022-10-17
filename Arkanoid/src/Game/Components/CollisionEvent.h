#pragma once
#include "ICollider.h"
namespace ArcanoidGame
{
	class CollisionEvent
	{
	public:
		virtual void OnCollision(ICollider& other, Vector& contactPoint) = 0;
	};
}