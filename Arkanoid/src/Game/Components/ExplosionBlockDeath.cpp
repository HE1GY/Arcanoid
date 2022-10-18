#include "ExplosionBlockDeath.h"

namespace ArcanoidGame
{
	ExplosionBlockDeath::ExplosionBlockDeath(GameFactory* gameFactory):
		_gameFactory(gameFactory)
	{
		_explosionBall = _gameFactory->CreateBall();
		_explosionBall->SetSize(100, 100);
		_explosionBall->Enable = false;
		_explosionBall->Visualization = false;
	}
	void ExplosionBlockDeath::OnCollision(ICollider& other, Vector& contactPoint)
	{
		if(other.Parent->ObjType == Ball)
		{
			if(Parent->Enable && !_explosionBall->Enable)
			{
				_explosionBall->Position = Vector(Parent->Position.X - 17, Parent->Position.Y - _explosionBall->Size.Y / 4 - 10);
				_explosionBall->Enable = true;
				_frameDelayForExplosion = 2;
				_killer = &other;
			}
		}
		
	}
	void ExplosionBlockDeath::Update()
	{
		if(_explosionBall->Enable)
		{
			_frameDelayForExplosion--;
		}

		if(_frameDelayForExplosion <= 0 &&_explosionBall->Enable)
		{
			_explosionBall->Enable = false;
			Parent->Enable=false;
			for(auto& listener : DeathListeners)
			{
				listener->OnDeath(_killer->Parent);
			}
		}
	}
}