#pragma once
#include "ICollider.h"

namespace ArcanoidGame
{
	class BoxCollider : public ICollider
	{
	public:
		Vector& ClosestPoint(Vector& target);
		void Update()override;
		void OnCollision(GameObject& other)override;
	private:
		int _top, _down, _right, _left;
	};
}