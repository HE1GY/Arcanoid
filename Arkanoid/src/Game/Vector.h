#pragma once
#include <math.h>  
#include <algorithm>

namespace ArcanoidGame
{

	class Vector
	{
	public:
		int X, Y;
		Vector():
			X(0.f),Y(0.f)
		{
		}

		Vector(int x, int y) :
			X(x), Y(y)
		{
		}

		explicit Vector(const Vector& vector)
		{
			X = vector.X;
			Y = vector.Y;
		}


		static int Magnitude(Vector& a, Vector& b)
		{
			return sqrt((b.X - a.X) * (b.X - a.X) + ((b.Y - a.Y) * (b.Y - a.Y)));
		}

		static Vector& Clamp(Vector& vector, Vector& min, Vector& max)
		{
			return *(new Vector(std::clamp(vector.X, min.X,max.X), std::clamp(vector.Y, min.Y, max.Y)));
		}


		Vector& operator + (const Vector& vector)
		{
			this->X += vector.X;
			this->Y += vector.Y;
			return *this;
		}
		Vector& operator * (const int& a)
		{
			this->X *= a;
			this->Y *= a;
			return *this;
		}

		Vector& operator = ( const Vector& vector)
		{
			X = vector.X;
			Y = vector.Y;
			return *this;
		}

		Vector& operator += (const Vector& vector)
		{
			return *this + vector;
		}

	};
}