#include "Window.h"

namespace ArcanoidGame
{
	void Window::OnPreInit(int& width, int& height, bool& fullscreen)
	{
		width = Width;
		height = Height;
		fullscreen = _fullscreen;
	}
	void Window::SetParameters(int width, int height, bool fullscreen)
	{
		Width = width;
		Height = height;
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


