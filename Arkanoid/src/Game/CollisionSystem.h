#pragma once
#include <vector>
#include "ICollider.h"
#include "BoxCollider.h"
#include "CirculCollider.h"

namespace ArcanoidGame
{
	class CollisionSystem
	{
	public:
		void AddBoxCollider(BoxCollider* collider);
		void AddCirculCollider(CirculCollider* collider);
		void CheckAllCollision();
		
	private:
		std::vector<BoxCollider*> _boxColliders;
		std::vector<CirculCollider*> _circulColliders;
	};
}