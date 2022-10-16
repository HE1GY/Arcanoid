#include "BallMover.h"
#include <iostream>
namespace ArcanoidGame
{
	BallMover::BallMover(const Vector& direction, std::shared_ptr <Window> window)
		:_direction(direction),IsMoving(false),Speed(0),_window(window)
	{
	}

	void BallMover::Update()
	{

		if(IsMoving)
		{
			Parent->Position += _direction * Speed;
			WallReflect();
		}
	}

	void BallMover::Reflect(Vector& normal)
	{
		_direction = Vector::Reflect(_direction, normal);
	}

	void BallMover::WallReflect()
	{
		int w, h;
		Parent->GetSize(w, h);
		Vector& center = Parent->Position + Vector(w, h);

		if(center.Y- h < 0)
		{
			Reflect(*new Vector(0, 1));
		}
		else if(center.Y > _window->Height)
		{
			Reflect(*new Vector(0, -1));
		}
		else if(center.X  > _window->Width)
		{
			Reflect(*new Vector(-1, 0));
		}
		else if(center.X - w < 0)
		{
			Reflect(*new Vector(1, 0));
		}
	}
}