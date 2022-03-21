#include "IssacGame.h"
#include "EndingLevel.h"
#include "PlayLevel.h"
#include "TitleLevel.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>


IssacGame::IssacGame() 
{
}

IssacGame::~IssacGame() 
{
}

void IssacGame::GameInit()
{
	GameEngineWindow::GetInst().SetWindowSizeAndPosition({ 0, 0 }, {1280, 720});

	GameEngineImageManager::GetInst()->Load("D:\\APIPortfolio\\AR40API\\Resources\\Playerable\\Isaac-head.bmp", "Isaac-head.bmp");

	CreateLevel<TitleLevel>("Title");
	CreateLevel<PlayLevel>("Play");
	CreateLevel<EndingLevel>("Ending");
	ChangeLevel("Play");
}

void IssacGame::GameLoop()
{

}

void IssacGame::GameEnd()
{

}