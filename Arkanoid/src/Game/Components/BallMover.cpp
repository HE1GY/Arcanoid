#include "BallMover.h"
namespace ArcanoidGame
{
	BallMover::BallMover(std::shared_ptr <Window> window)
		:Direction(Vector()),IsMoving(false),Speed(0),_window(window)
	{
	}

	void BallMover::Update()
	{
		if(IsMoving)
		{
			Parent->Position += Direction * Speed;
			WallReflect();
		}
	}

	void BallMover::Reflect(Vector& normal)
	{
		if(Vector::DotProduct(normal, Direction) < 0)
		{
			Direction = Vector::Reflect(Direction, normal);
		}
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