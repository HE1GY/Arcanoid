#pragma once

namespace ArcanoidGame
{
	class Window
	{
	public:
		void OnPreInit(int& width, int& height, bool& fullscreen);
		void SetParameters(int width, int height, bool fullscreen);
		bool TryInit();
		void OnClose();
	private:
		 int _width;
		 int _height;
		bool _fullscreen;
	};
}
