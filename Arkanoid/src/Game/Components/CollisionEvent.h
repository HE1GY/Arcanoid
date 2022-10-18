#pragma once

namespace ArcanoidGame
{
	class ICollider;
	class Vector;

	class CollisionEvent
	{
	public:
		virtual void OnCollision(ICollider& other, Vector& contactPoint) = 0;
	};
}