#pragma once
#include "ICollider.h"
#include "BallMover.h"

namespace ArcanoidGame
{
	class CirculCollider:public ICollider
	{
	public :
		int Radius;
		Vector Center;

		Vector& GetNormalAt(Vector& point)override;
		void OnCollision(ICollider& other, Vector& contactPoint)override;
		void Update()override;
	};
}