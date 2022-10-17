#include "GameFactory.h"
#include "Framework.h"
#include "CommonBlockDeath.h"
#include "ExplosionBlockDeath.h"
#include "CollisionAlongMove.h"

namespace ArcanoidGame
{
	GameFactory::GameFactory(std::shared_ptr <CollisionSystem> collisionSys, std::shared_ptr <Window> window):
	_collisionSys(collisionSys),_window(window)
	{
	}

	

	int GameFactory::GetScaledSize(const int& defaultWindowValue, const int& currentWindowValue, const int& defautValue)
	{
		return currentWindowValue * defautValue / defaultWindowValue;
	}

	GameObject* GameFactory::CreateBall()
	{
		GameObject* ball = new GameObject(createSprite("res/data/63-Breakout-Tiles.png"),Ball);
		RegisterGameObject(ball);
		int width = GetScaledSize(Window::DefaultWidth,  _window->Width, 25);
		int height = GetScaledSize(Window::DefaultHeight, _window->Height, 25);
		ball->SetSize(width, height);

		BallMover* ballMover = new BallMover(_window);
		ball->AddComponent(ballMover);

		CollisionAlongMove* collisionAlongMove = new CollisionAlongMove(Ball, ballMover);
		ball->AddComponent(collisionAlongMove);

		CirculCollider* circul = new CirculCollider();
		circul->CollidedEvent = collisionAlongMove;
		ball->AddComponent(circul);
		_collisionSys->AddCirculCollider(circul);


		//TO DELETE
		ballMover->IsMoving = true;
		ballMover->Speed = 2;
		ballMover->Direction=Vector(1,1);

		return ball;
	}

	
	GameObject* GameFactory::CreatePlatform()
	{
		GameObject* platform = new GameObject(createSprite("res/data/51-Breakout-Tiles.png"), Platform);
		RegisterGameObject(platform);
		int width = GetScaledSize(Window::DefaultWidth,  _window->Width, 200);
		int height = GetScaledSize(Window::DefaultHeight, _window->Height, 35);
		platform->SetSize(width, height);

		BoxCollider* box = new BoxCollider();
		platform->AddComponent(box);
		_collisionSys->AddBoxCollider(box);

		PlatformInput* controll = new PlatformInput(_window);
		platform->AddComponent(controll);

		return platform;
	}

	GameObject* GameFactory::CreateCommonBlock()
	{
		GameObject* commonBlock = new GameObject(createSprite("res/data/01-Breakout-Tiles.png"), Block);
		RegisterGameObject(commonBlock);
		int width = GetScaledSize(Window::DefaultWidth, _window->Width, 75);
		int height = GetScaledSize(Window::DefaultHeight, _window->Height, 25);
		commonBlock->SetSize(width, height);

		BoxCollider* box = new BoxCollider();
		commonBlock->AddComponent(box);
		_collisionSys->AddBoxCollider(box);

		CommonBlockDeath* death = new CommonBlockDeath();
		commonBlock->AddComponent(death);
		box->CollidedEvent = death;

		return commonBlock;
	}
	GameObject* GameFactory::CreateExplosionBlock()
	{
		GameObject* explosionBlock = new GameObject(createSprite("res/data/09-Breakout-Tiles.png"), Block);
		RegisterGameObject(explosionBlock);
		int width = GetScaledSize(Window::DefaultWidth, _window->Width, 75);
		int height = GetScaledSize(Window::DefaultHeight, _window->Height, 25);
		explosionBlock->SetSize(width, height);

		BoxCollider* box = new BoxCollider();
		explosionBlock->AddComponent(box);
		_collisionSys->AddBoxCollider(box);

		ExplosionBlockDeath* death = new ExplosionBlockDeath(this);
		box->CollidedEvent = death;
		explosionBlock->AddComponent(death);

		return explosionBlock;
	}



	GameObject* GameFactory::CreateEncresesAbility()
	{
		GameObject* ability = new GameObject(createSprite("res/data/62-Breakout-Tiles.png"),Ability);
		RegisterGameObject(ability);
		int width = GetScaledSize(Window::DefaultWidth, _window->Width, 25);
		int height = GetScaledSize(Window::DefaultHeight, _window->Height, 25);
		ability->SetSize(width, height);

		CirculCollider* collider = new CirculCollider();
		ability->AddComponent(collider);
		_collisionSys->AddCirculCollider(collider);

		BallMover* ballMover = new BallMover(_window);
		ballMover->IsMoving=true;
		ballMover->Direction=Vector(0,1);
		ballMover->Speed = 1;
		ability->AddComponent(ballMover);

		CollisionAlongMove* collisionAlongMove = new CollisionAlongMove(Ability, ballMover);
		ability->AddComponent(collisionAlongMove);

		collider->CollidedEvent = collisionAlongMove;

		return ability;
	}
	GameObject* GameFactory::CreateDecreasesAbility()
	{
		GameObject* ability =new GameObject(createSprite("res/data/64-Breakout-Tiles.png"),Ability);
		RegisterGameObject(ability);
		int width = GetScaledSize(Window::DefaultWidth, _window->Width, 25);
		int height = GetScaledSize(Window::DefaultHeight, _window->Height, 25);
		ability->SetSize(width, height);


		return ability;
	}
	void GameFactory::RegisterGameObject(GameObject* gameObject)
	{
		GameObjects.push_back(gameObject);
	}

	
}