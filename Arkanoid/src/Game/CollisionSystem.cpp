#include "CollisionSystem.h"

namespace ArcanoidGame
{
	void CollisionSystem::AddBoxCollider(BoxCollider* collider)
	{
		_boxColliders.push_back(collider);
	}

	void CollisionSystem::AddCirculCollider(CirculCollider* collider)
	{
		_ballCollider = collider;
	}


	void CollisionSystem::CheckAllCollision()
	{
		for(auto& box: _boxColliders)
		{
			Vector& closesPoint=box->ClosestPoint(_ballCollider->Center);
			int distance=Vector::Magnitude(closesPoint, _ballCollider->Center);
			if(distance < _ballCollider->Radius)
			{
				box->OnCollision(*_ballCollider->Parent);
				_ballCollider->OnCollision(*box->Parent);
			}
		}
	}
}