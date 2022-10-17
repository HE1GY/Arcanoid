#include "CollisionSystem.h"

namespace ArcanoidGame
{
	void CollisionSystem::AddBoxCollider(BoxCollider* collider)
	{
		_boxColliders.push_back(collider);
	}


	void CollisionSystem::AddCirculCollider(CirculCollider* collider)
	{
		_circulColliders.push_back(collider);
	}


	void CollisionSystem::CheckAllCollision()
	{
		for(auto& boxCollider: _boxColliders)
		{
			if(boxCollider->Parent->Enable)
			{
				for(auto& circulCollider : _circulColliders)
				{
					if(circulCollider->Parent->Enable)
					{
						Vector& closesPoint = boxCollider->ClosestPointTo(circulCollider->Center);
						int distance = Vector::MagnitudeBetween(closesPoint, circulCollider->Center);

						if(distance < circulCollider->Radius)
						{
							circulCollider->OnCollision(*boxCollider, closesPoint);
							boxCollider->OnCollision(*circulCollider, closesPoint);
						}
					}
				}
			}
		}
	}
}