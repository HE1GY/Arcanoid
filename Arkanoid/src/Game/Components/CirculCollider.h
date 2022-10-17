#pragma once
#include "ICollider.h"
#include "BallMover.h"
#include "CollisionEvent.h."

namespace ArcanoidGame
{
	class CirculCollider:public ICollider
	{
	public :
		CollisionEvent* CollidedEvent;
		int Radius;
		Vector Center;

		Vector& GetNormalAt(Vector& point)override;
		void OnCollision(ICollider& other, Vector& contactPoint)override;
		void Update()override;
	};
}