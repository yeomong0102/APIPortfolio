#include "Bullet.h"
#include <GameEngineBase/GameEngineTime.h>

Bullet::Bullet() 
{
}

Bullet::~Bullet() 
{
}

void Bullet::Start()
{
	CreateRenderer("Goldbar.bmp");
	// Time_ = 2.0f;

	Death(2.0f);
}

void Bullet::Update()
{
	/*Time_ -= GameEngineTime::GetDeltaTime();

	if (0.0f >= Time_)
	{
		Off();
		return;
	}*/

	SetMove(float4::RIGHT * GameEngineTime::GetDeltaTime() * 200.0f);
}