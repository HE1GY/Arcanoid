#include "CommonBlockDeath.h"

namespace ArcanoidGame
{
	void CommonBlockDeath::OnCollision(ICollider& other, Vector& contactPoint)
	{
		Parent->Enable=false;
	}

	void CommonBlockDeath::Update()
	{
	}
}
