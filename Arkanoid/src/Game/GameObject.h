#pragma once
#include "Vector.h"
#include <vector>
#include "Framework.h"
#include "IComponent.h"



namespace ArcanoidGame
{

	enum ObjectType
	{
		Platform,
		Ball,
		Block,
		AbilityDecreases,
		AbilityEncreses,
		Area
	};

	class GameObject
	{
	public:
		ObjectType ObjType;
		bool Enable;
		bool Visualization;
		Vector Position;
		Vector Size;
		GameObject(Sprite* sprite, ObjectType type);
		 void GetSize(int& w, int& h);
		 void SetSize(int w, int h);

		 void AddComponent(IComponent* component);
		 void UpdateComponents();
		 void Draw();
		 
	private:
		std::vector <IComponent*> Components;
		Sprite* _sprite;
	};

	


}