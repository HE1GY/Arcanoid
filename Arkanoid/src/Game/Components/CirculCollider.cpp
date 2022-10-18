#include "CirculCollider.h"
#include "CollisionEvent.h"
namespace ArcanoidGame
{

	void CirculCollider::Update()
	{
		int w, h;
		Parent->GetSize(w, h);
		Radius = w/2;
		Center = Parent->Position+Vector(w/2,h/2);
	}

	void CirculCollider::OnCollision(ICollider& other, Vector& contactPoint)
	{
		for(auto& collisionListener : CollisionListeners)
			collisionListener->OnCollision(other, contactPoint);
	}

	Vector& CirculCollider::GetNormalAt(Vector& point)
	{
		return *(new Vector(0, 0));//TODO
	}

}
