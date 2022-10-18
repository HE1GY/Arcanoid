#pragma once
#include "GameObject.h"
#include "BallMover.h"
#include "CollisionEvent.h"
#include "ICollider.h"


namespace ArcanoidGame
{
	class CollisionAlongMove:public IComponent,public CollisionEvent
	{
	public:
		CollisionAlongMove(ObjectType type, BallMover* ballMove);
		void Update()override;
		void OnCollision(ICollider& other, Vector& contactPoint) override;
	private:
		BallMover* _ballMove;
		ObjectType _type;
		GameObject* _collisionWith;
	};
}