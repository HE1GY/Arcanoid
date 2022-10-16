#pragma once
#include <math.h>  
#include <algorithm>

namespace ArcanoidGame
{

	class Vector
	{
	public:
		float X, Y;
		Vector():
			X(0),Y(0)
		{
		}

		Vector(float x, float y) :
			X(x), Y(y)
		{
		}

		explicit Vector(const Vector& vector)
		{
			X = vector.X;
			Y = vector.Y;
		}


		static float MagnitudeBetween(Vector& a, Vector& b)
		{
			return sqrt((b.X - a.X) * (b.X - a.X) + ((b.Y - a.Y) * (b.Y - a.Y)));
		}
		static Vector& Clamp(Vector& vector, Vector& top, Vector& down, Vector& right, Vector& left)
		{
			return *(new Vector(std::clamp(vector.X, left.X, right.X), std::clamp(vector.Y, top.Y, down.Y)));
		}
		static float DotProduct(Vector& a, Vector& b)
		{
			return (a.X*b.X)+(a.Y*b.Y);
		}

		static Vector& Reflect(Vector& direction, Vector& normal)
		{
			Vector& flippefNormal = normal * -1;
			Vector& projection = normal *DotProduct(direction,flippefNormal);
			Vector& reflected= (direction + (projection * 2 ));
			return reflected;
		}




		float Magnitude()
		{
			return sqrt(this->X* this->X  + this->Y * this->Y);
		}

		

		void Normalize()
		{
			float magnitude = Magnitude();
			this->X /= magnitude;
			this->Y /= magnitude;
		}


		Vector& operator + (const Vector& vector)
		{
			Vector* newVector = new Vector(this->X + vector.X, this->Y + vector.Y);
			return *newVector;
		}

		Vector& operator - (const Vector& vector)
		{
			Vector* newVector = new Vector(this->X - vector.X, this->Y - vector.Y);
			return *newVector;
		}
		Vector& operator * (const float& a)
		{
			Vector* newVector = new Vector(this->X * a, this->Y * a);
			return *newVector;
		}

		Vector& operator = ( const Vector& vector)
		{
			X = vector.X;
			Y = vector.Y;
			return *this;
		}

		Vector& operator += (const Vector& vector)
		{
			this->X += vector.X;
			this->Y += vector.Y;
			return *this;
		}

	};
}