#pragma once
#include "IComponent.h"

namespace ArcanoidGame
{
	class ICollider :public IComponent
	{
		virtual void OnCollision(GameObject& other) = 0;
	};
}