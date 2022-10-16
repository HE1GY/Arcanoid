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

		 int Width;
		 int Height;

	private:
		bool _fullscreen;
	};
}
