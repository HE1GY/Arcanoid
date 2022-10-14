#pragma once
#include "GameObjectParameters.h"


extern class Sprite;

namespace ArcanoidGame
{
	class GameObject
	{
	public:
		Position Position;
		Sprite* Sprite;
		//Colider

		 void GetSize(int& w, int& h);
		 void SetSize(int w, int h);
		 void Destroy();
	private:
		Size _size;
	};
}