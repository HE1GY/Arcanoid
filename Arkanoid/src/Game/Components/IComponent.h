#pragma once
#include "GameObject.h"

namespace ArcanoidGame
{
	class GameObject;

	class IComponent
	{
	public:
		GameObject* Parent;
		virtual void Update() = 0;
	};

}