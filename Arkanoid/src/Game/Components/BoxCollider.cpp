#include "BoxCollider.h"


namespace ArcanoidGame
{
	void BoxCollider::Update()
	{
		int w, h;
		Parent->GetSize(w, h);
		Center = Parent->Position+Vector(w/2, h/2);
		_top = Parent->Position+Vector(w/2,0);
		_down = Parent->Position+Vector(w/2, h);
		_right = Parent->Position+Vector(w,h/2);
		_left = Parent->Position + Vector(0, h/2);
	}
	Vector& BoxCollider::ClosestPointTo(Vector& target)
	{
		return Vector::Clamp(target, _top, _down, _right, _left);;
	}

	Vector& BoxCollider::GetNormalAt(Vector& point)
	{
		Vector* normal = new Vector();

		if( abs(point.Y - _top.Y) <= 1)
		{
			*normal += Vector(0, -1);
		}

		if(abs(point.X - _right.X) <= 1)
		{
			*normal += Vector(1, 0);
		}

		if(abs(point.Y - _down.Y) <= 1)
		{
			*normal += Vector(0, 1);
		}

		if(abs(point.X - _left.X) <= 1)
		{
			*normal += Vector(-1, 0);
		}

		normal->Normalize();
		return *normal;
	}

	void BoxCollider::OnCollision(ICollider& other, Vector& contactPoint)
	{
		if(CollidedEvent != nullptr)
		{
			CollidedEvent->OnCollision(other, contactPoint);
		}
	}
}