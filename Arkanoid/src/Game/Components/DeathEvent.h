#pragma once


namespace ArcanoidGame
{
	class GameObject;
	class DeathEventListener
	{
	public:
		virtual void OnDeath(GameObject* gameObject) = 0;
	};
}