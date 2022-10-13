#pragma once
#include "Framework.h"
#include<iostream>

std::ostream& operator << (std::ostream& stream, const FRKey k)
{
	switch(k)
	{
		case FRKey::LEFT:
			std::cout << "Left" ;
			break;
		case FRKey::RIGHT:
			std::cout << "Right" ;
			break;
		case FRKey::DOWN:
			std::cout << "DOWN";
			break;
		case FRKey::UP:
			std::cout << "UP" ;
			break;
		case FRKey::COUNT:
			std::cout << "COUNT" ;
			break;
		
		default:
			break;
	}
	return stream;
}

std::ostream& operator << (std::ostream& stream, const FRMouseButton k)
{
	switch(k)
	{
		case FRMouseButton::LEFT:
			std::cout << "LeftM";
			break;
		case FRMouseButton::RIGHT:
			std::cout << "RightM";
			break;
		case FRMouseButton::COUNT:
			std::cout << "COUNTM";
			break;
		case FRMouseButton::MIDDLE:
			std::cout << "MIDDLEM";
			break;

		default:
			break;
	}
	return stream;
}