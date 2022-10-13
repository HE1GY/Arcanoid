#include "Framework.h"
#include "Window.h"
#include "InputManager.h"
#include "GameLogic.h"
#include <memory>

#include "iostream"
#include <stdlib.h>


class Arkanoid : public Framework
{
public:
	Arkanoid()
	{
		_window = std::make_unique<ArcanoidGame::Window>();
		_input = std::make_unique<ArcanoidGame::InputManager>();
		_gameLogic = std::make_unique<ArcanoidGame::GameLogic>();
	}

	~Arkanoid()override
	{
	}

	void PreInit(int& width, int& height, bool& fullscreen)override
	{
		_window->OnPreInit(width, height, fullscreen);
	}

	bool Init()override
	{
		return _window->TryInit();
	}

	void Close()override
	{
		_window->OnClose();
	}

	bool Tick()override
	{
		drawTestBackground();
		_gameLogic->OnTick();
		return false;
	}



	void onMouseMove(int x, int y, int xrelative, int yrelative)override
	{
		_input->OnMouseMove(x, y, xrelative, yrelative);
	}

	void onMouseButtonClick(FRMouseButton button, bool isReleased)override
	{
		_input->OnMouseButtonClick(button, isReleased);
	}

	void onKeyPressed(FRKey k)override
	{
		_input->OnKeyPressed(k);
	}

	void onKeyReleased(FRKey k)override
	{
		_input->OnKeyReleased(k);
	}



	const char* GetTitle() override
	{
		return "Arcanoid";
	}

	void SetWindowParameters(int width, int height, bool fullscreen)
	{
		_window->SetParameters(width, height, fullscreen);
	}



private:
	std::unique_ptr<ArcanoidGame::Window> _window;
	std::unique_ptr<ArcanoidGame::InputManager> _input;
	std::unique_ptr<ArcanoidGame::GameLogic> _gameLogic;
};


int main(int argc, char* argv[])
{
	int width=960;
	int height = 540;
	int windowArgCount = 0;

	for(size_t i = 0; i < argc; i++)
	{
		if(strcmp(argv[i],"-window")==0)
		{
			windowArgCount = 2;
		}
		else if(windowArgCount == 2)
		{
			width = strtol(argv[i], NULL, 10);
			windowArgCount--;
		}
		else if(windowArgCount == 1)
		{
			height = strtol(argv[i], NULL, 10);
			windowArgCount--;
		}
	}

	std::unique_ptr<Arkanoid> arcanoid = std::make_unique<Arkanoid>();
	arcanoid->SetWindowParameters(width, height, false);
	int code = run(arcanoid.get());
	return code;
}

