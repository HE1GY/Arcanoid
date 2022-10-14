#include "Window.h"

namespace ArcanoidGame
{
	void Window::OnPreInit(int& width, int& height, bool& fullscreen)
	{
		width = _width;
		height = _height;
		fullscreen = _fullscreen;
	}
	void Window::SetParameters(int width, int height, bool fullscreen)
	{
		_width = width;
		_height = height;
		_fullscreen = fullscreen;
	}
	bool Window::TryInit()
	{

		return true;
	}
	void Window::OnClose()
	{

	}

}


