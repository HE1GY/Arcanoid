#pragma once
#include "IComponent.h"

namespace ArcanoidGame
{
	class ICollider :public IComponent
	{
	public:
		virtual Vector& GetNormalAt(Vector& point) = 0;
		virtual void OnCollision(ICollider& other,Vector& contactPoint) = 0;
	};
}