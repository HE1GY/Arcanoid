#include "CollisionAlongMove.h"


namespace ArcanoidGame
{
	CollisionAlongMove::CollisionAlongMove(ObjectType type, BallMover* ballMove):
		_type(type),_ballMove(ballMove)
	{
	}

	void CollisionAlongMove::Update()
	{
		if(_type == AbilityDecreases || _type == AbilityEncreses)
		{
			if(_collisionWith != nullptr && _collisionWith->Enable)
			{
				_ballMove->IsMoving = false;
			}
			else
			{
				_collisionWith = nullptr;
				_ballMove->IsMoving = true;
			}
		}
	}
	void CollisionAlongMove::OnCollision(ICollider& other, Vector& contactPoint)
	{
		if(_type == AbilityDecreases || _type == AbilityEncreses)
		{
			switch(other.Parent->ObjType)
			{
				case ArcanoidGame::Block:
					_ballMove->IsMoving=false;
					_collisionWith = other.Parent;
					break;
				case ArcanoidGame::Ball:
					break;
				case ArcanoidGame::Platform:
					Parent->Enable = false;
					break;
				default:
					break;
			}
		}
		else if(_type == Ball)
		{
			switch(other.Parent->ObjType)
			{
				case ArcanoidGame::Platform:
					_ballMove->Reflect(other.GetNormalAt(contactPoint));
					break;
				case ArcanoidGame::Ball:
					break;
				case ArcanoidGame::Block:
					_ballMove->Reflect(other.GetNormalAt(contactPoint));
					break;
				default:
					break;
			}
		}
	}
}