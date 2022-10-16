#include "CirculCollider.h"

namespace ArcanoidGame
{
	CirculCollider::CirculCollider(BallMover* ballMover):
		_ballMover(ballMover),Radius(0),Center(0,0)
	{
	}

	void CirculCollider::Update()
	{
		int w, h;
		Parent->GetSize(w, h);
		Radius = w/2;
		Center = Parent->Position+Vector(w/2,h/2);
	}

	void CirculCollider::OnCollision(ICollider& other, Vector& contactPoint)
	{
		_ballMover->Reflect(other.GetNormalAt(contactPoint));
	}

	Vector& CirculCollider::GetNormalAt(Vector& point)
	{
		return *(new Vector(0, 0));//TODO
	}

}
