#pragma once


namespace ArcanoidGame
{
	class ModifierEvent
	{
	public:
		virtual void OnDecreases() = 0;
		virtual void OnEncreses() = 0;
	};
}