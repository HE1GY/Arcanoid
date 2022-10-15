#include "BoxCollider.h"

namespace ArcanoidGame
{
	void BoxCollider::Update()
	{
		int w, h;
		Parent->GetSize(w, h);
		_top = Parent->Position.Y;
		_down = Parent->Position.Y+2*h;
		_right = Parent->Position.X +2*w;
		_left = Parent->Position.X;
	}
	Vector& BoxCollider::ClosestPoint(Vector& target)
	{
		int clX = std::clamp(target.X, _left, _right);
		int clY = std::clamp(target.Y, _top,_down );

		return *(new Vector(clX, clY));
	}

	void BoxCollider::OnCollision(GameObject& other)
	{
		
	}
}