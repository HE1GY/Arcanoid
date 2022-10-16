#pragma once
#include "IComponent.h"
#include <memory>
#include "Window.h"
#include "Vector.h"

namespace ArcanoidGame
{
	class BallMover:public IComponent
	{
	public: 
		bool IsMoving;
		int Speed;

		BallMover(const Vector& startVelocity, std::shared_ptr <Window> window);
		void Update()override;
		void Reflect(Vector& normal);
		
	private: 
		Vector _direction;
		std::shared_ptr <Window> _window;

		void WallReflect();
	};
}