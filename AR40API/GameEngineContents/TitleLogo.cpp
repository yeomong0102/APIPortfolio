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
	SetPosition({ 640, 150 });
	SetScale({ 900, 200 });
}

void TitleLogo::Render()
{
	DebugRectRender();
	// 
}