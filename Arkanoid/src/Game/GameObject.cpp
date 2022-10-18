#include "GameObject.h"
#include "Framework.h"


namespace ArcanoidGame
{

	 GameObject::GameObject(Sprite* sprite,ObjectType type) :
		_sprite(sprite),Enable(true),Visualization(true), ObjType(type)
	{
	}
	void GameObject::GetSize(int& w, int& h)
	{
		w = Size.X;
		h = Size.Y;
	}
	void GameObject::SetSize(int w, int h)
	{
		Size.X = w;
		Size.Y=h;
		setSpriteSize(_sprite, w, h);
	}

	void GameObject::AddComponent(IComponent* component)
	{
		component->Parent = this;
		Components.push_back(component);
	}


	void GameObject::UpdateComponents()
	{
		if(Enable)
		{
			for(auto& component : Components)
			{
				component->Update();
			}
		}
	}

	void GameObject::Draw()
	{
		if(Enable && Visualization)
		{
			drawSprite(_sprite, Position.X, Position.Y);
		}
	}

}