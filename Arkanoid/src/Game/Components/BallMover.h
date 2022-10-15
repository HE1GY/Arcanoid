#pragma once
#include "IComponent.h"

namespace ArcanoidGame
{
	class BallMover:public IComponent
	{
	public: 
		BallMover(const Vector& startVelocity);
		void Update()override;
		bool IsMoving;
		float Speed;
	private: 
		Vector _velocity;
	};
}