#pragma once
#include "IComponent.h"
#include "Vector.h"
#include "CollisionEvent.h"
#include <vector>

namespace ArcanoidGame
{
	class ICollider :public IComponent
	{
	public:
		virtual Vector& GetNormalAt(Vector& point) = 0;
		virtual void OnCollision(ICollider& other,Vector& contactPoint) = 0;
		std::vector<CollisionEvent*> CollisionListeners;
	};
}