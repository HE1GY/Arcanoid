#include "CollisionAlongMove.h"


namespace ArcanoidGame
{
	CollisionAlongMove::CollisionAlongMove(ObjectType type, BallMover* ballMove):
		_type(type),_ballMove(ballMove)
	{
	}

	void CollisionAlongMove::Update()
	{
	}
	void CollisionAlongMove::OnCollision(ICollider& other, Vector& contactPoint)
	{
		if(_type == Ability)
		{
			switch(other.Parent->ObjType)
			{
				case ArcanoidGame::Platform:
					_ballMove->IsMoving=false;
					break;
				case ArcanoidGame::Ball:
					break;
				case ArcanoidGame::Block:
					Parent->Enable = false;
					break;
				case ArcanoidGame::Ability:
					break;
				case ArcanoidGame::Area:
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
				case ArcanoidGame::Ability:
					break;
				case ArcanoidGame::Area:
					break;
				default:
					break;
			}
		}
	}
}