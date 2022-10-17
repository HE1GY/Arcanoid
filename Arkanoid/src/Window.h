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

		 inline static int DefaultWidth;
		 inline static int DefaultHeight;

	private:
		bool _fullscreen;
	};
}
