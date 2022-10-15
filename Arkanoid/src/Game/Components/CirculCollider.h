#pragma once
#include "ICollider.h"


namespace ArcanoidGame
{
	class CirculCollider:public ICollider
	{
	public :
		int Radius;
		Vector Center;

		void OnCollision(GameObject& other)override;
		void Update()override;
	};
}