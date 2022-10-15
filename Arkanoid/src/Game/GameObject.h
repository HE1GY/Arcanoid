#pragma once
#include "Vector.h"
#include "InputManager.h"
#include <vector>
#include "IComponent.h"



namespace ArcanoidGame
{
	class IComponent;

	class GameObject
	{
	public:
		Vector Position;
		Sprite* Sprite; 
		//Colider

		 void GetSize(int& w, int& h);
		 void SetSize(int w, int h);

		 void AddComponent(IComponent* component);

		 virtual void Destroy();
		 void UpdateComponents();
	private:
		Vector _size;
		std::vector <IComponent*> _components;
	};
}