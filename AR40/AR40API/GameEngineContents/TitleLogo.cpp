#include "TitleLogo.h"
#include <Windows.h>
#include <GameEngineBase/GameEngineWindow.h>

TitleLogo::TitleLogo() 
{
}

TitleLogo::~TitleLogo() 
{
}

void TitleLogo::Start()
{
	SetPosition(GameEngineWindow::GetScale().Half());
	SetScale({ 900, 900 });
}

void TitleLogo::Render()
{
	DebugRectRender();
	// 
}