#include "BallMover.h"

namespace ArcanoidGame
{
	BallMover::BallMover(const Vector& startVelocity):
		_velocity(startVelocity),IsMoving(false),Speed(0)
	{
	}

	void BallMover::Update()
	{
		if(IsMoving)
		{
			Parent->Position += _velocity * Speed;
		}
	}
}