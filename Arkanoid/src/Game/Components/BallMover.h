#pragma once
#include <memory>
#include "Window.h"
#include "IComponent.h"
#include "GameObject.h"

namespace ArcanoidGame
{
	class BallMover:public IComponent
	{
	public: 
		bool IsMoving;
		int Speed;
		Vector Direction;

		BallMover(std::shared_ptr	<Window> window);
		void Update()override;
		void Reflect(Vector& normal);
		
	private: 
		std::shared_ptr	<Window> _window;

		void WallReflect();
	};
}