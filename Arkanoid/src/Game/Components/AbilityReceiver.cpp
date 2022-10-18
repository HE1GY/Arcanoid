#include "AbilityReceiver.h"
#include "ICollider.h"
namespace ArcanoidGame
{

	void AbilityReceiver::Update()
	{
	}
	void AbilityReceiver::OnCollision(ICollider& other, Vector& contactPoint)
	{
		if(other.Parent->ObjType ==AbilityEncreses )
		{
			ModifierEventListener->OnEncreses();
		}
		else if(other.Parent->ObjType == AbilityDecreases)
		{
			ModifierEventListener->OnDecreases();
		}
	}
}