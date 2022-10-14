#include "GameObject.h"
#include "Framework.h"

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
	void GameObject::Destroy()
	{
		destroySprite(Sprite);
	}
}