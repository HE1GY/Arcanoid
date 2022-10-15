#include "CirculCollider.h"

namespace ArcanoidGame
{
	void CirculCollider::Update()
	{
		int w, h;
		Parent->GetSize(w, h);
		Radius = w;
		Center = Parent->Position;
	}

	void CirculCollider::OnCollision(GameObject& other)
	{

	}
}
