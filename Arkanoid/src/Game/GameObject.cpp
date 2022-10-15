#include "GameObject.h"
#include "Framework.h"
#include "IComponent.h"

namespace ArcanoidGame
{
	void GameObject::GetSize(int& w, int& h)
	{
		w = _size.X;
		h = _size.Y;
	}
	void GameObject::SetSize(int w, int h)
	{
		_size.X = w;
		_size.Y=h;
		setSpriteSize(Sprite, w, h);
	}

	void GameObject::AddComponent(IComponent* component)
	{
		component->Parent = this;
		_components.push_back(component);
	}


	void GameObject::UpdateComponents()
	{
		for(auto& component: _components)
		{
			component->Update();
		}
	}


	void GameObject::Destroy()
	{
		destroySprite(Sprite);
	}


}