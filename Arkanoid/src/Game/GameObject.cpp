#include "GameObject.h"
#include "Framework.h"
#include "IComponent.h"

namespace ArcanoidGame
{
	void GameObject::GetSize(int& w, int& h)
	{
		w = _size.Width;
		h = _size.Height;
	}
	void GameObject::SetSize(int w, int h)
	{
		_size.Width = w;
		_size.Height=h;
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