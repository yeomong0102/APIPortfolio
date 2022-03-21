#include "Player.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>

Player::Player() 
{
}

Player::~Player() 
{
}

void Player::Start()
{
	SetPosition(GameEngineWindow::GetScale().Half());
	SetScale({ 100, 100 });
	CreateRenderer("Isaac-head.bmp");
}

void Player::Render()
{
	// DebugRectRender();

	GameEngineImage* FindImage = GameEngineImageManager::GetInst()->Find("Isaac-head.bmp");

	if (nullptr == FindImage)
	{
		MsgBoxAssert("이미지를 찾지못했습니다")
	}

	GameEngine::BackBufferImage()->BitCopyBot(FindImage, GetPosition());
}