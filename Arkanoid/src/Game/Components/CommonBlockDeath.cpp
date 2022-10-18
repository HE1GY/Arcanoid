#include "CommonBlockDeath.h"
#include "GameObject.h"
#include "DeathEvent.h"
namespace ArcanoidGame
{
	void CommonBlockDeath::OnCollision(ICollider& other, Vector& contactPoint)
	{
		if(other.Parent->ObjType == Ball)
		{
			Parent->Enable = false;
			for(auto& listener : DeathListeners)
			{
				listener->OnDeath(other.Parent);
			}
		}
	}

	void CommonBlockDeath::Update()
	{
	}
}
