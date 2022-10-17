#pragma once
#include "ICollider.h"
#include "CollisionEvent.h."

namespace ArcanoidGame
{
	class BoxCollider : public ICollider 
	{
	public:
		CollisionEvent* CollidedEvent;

		Vector Center;
		Vector& ClosestPointTo(Vector& target);
		void Update()override;
		void OnCollision(ICollider& other, Vector& contactPoint)override;
		Vector& GetNormalAt(Vector& point)override;
	private:
		Vector _top, _down, _right, _left;
	};
}