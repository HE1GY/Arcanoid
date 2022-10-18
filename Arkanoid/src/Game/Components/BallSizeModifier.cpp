#include "BallSizeModifier.h"
#include "GameObject.h"
namespace ArcanoidGame
{
	BallSizeModifier::BallSizeModifier()
		:_minSize(0),_maxSize(0)
	{
	}

	
	void BallSizeModifier::Encreses()
	{
		/*if(Parent->Size.X < _maxSize && Parent->Size.Y < _maxSize)
		{*/
			float x = Parent->Size.X + Parent->Size.X * 0.4f;
			float y= Parent->Size.Y + Parent->Size.Y * 0.4f;
			Parent->SetSize(x, y);
		/*}*/
	}
	void BallSizeModifier::Decreases()
	{
		/*if(Parent->Size.X > _minSize && Parent->Size.Y < _minSize)
		{*/
			float x = Parent->Size.X - Parent->Size.X * 0.4f;
			float y = Parent->Size.Y - Parent->Size.Y * 0.4f;
			Parent->SetSize(x, y);
		/*}*/
	}
	void BallSizeModifier::Update()
	{
		if(_minSize==0 && _maxSize==0)
		{
			_minSize = Parent->Size.X * 0,5;
			_maxSize = Parent->Size.X * 2;
		}
	}

	void BallSizeModifier::OnEncreses()
	{
		Encreses();
	};
	void BallSizeModifier::OnDecreases()
	{
		Decreases();
	};
}