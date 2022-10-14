#include "GameFactory.h"
#include "Framework.h"


namespace ArcanoidGame
{
	GameObject* GameFactory::Create(const char* path)
	{
		GameObject* gameObject = new GameObject();
		gameObject->Sprite = createSprite(path);
		return gameObject;
	}
}