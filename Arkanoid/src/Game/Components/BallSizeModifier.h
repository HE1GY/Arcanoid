#pragma once
#include "IComponent.h"
#include "ModifierEvent.h"

namespace ArcanoidGame
{
	class BallSizeModifier :public IComponent, public ModifierEvent
	{
	public:
		BallSizeModifier();
		void Encreses();
		void Decreases();
		void OnEncreses()override;
		void OnDecreases()override;
		void Update()override;
	private:
		float _minSize;
		float _maxSize;
	};
}