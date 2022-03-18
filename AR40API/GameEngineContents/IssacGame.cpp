#include "IssacGame.h"
#include "EndingLevel.h"
#include "PlayLevel.h"
#include "TitleLevel.h"
#include <GameEngineBase/GameEngineWindow.h>


IssacGame::IssacGame() 
{
}

IssacGame::~IssacGame() 
{
}

void IssacGame::GameInit()
{
	GameEngineWindow::GetInst().SetWindowSizeAndPosition({ 0, 0 }, {1280, 720});

	CreateLevel<TitleLevel>("Title");
	CreateLevel<PlayLevel>("Play");
	CreateLevel<EndingLevel>("Ending");
	ChangeLevel("Title");
}

void IssacGame::GameLoop()
{

}

void IssacGame::GameEnd()
{

}