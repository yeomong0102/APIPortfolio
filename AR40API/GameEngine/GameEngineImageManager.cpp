#include "GameEngineImageManager.h"
#include <GameEngineBase/GameEngineDebug.h>

GameEngineImageManager* GameEngineImageManager::Inst_ = new GameEngineImageManager();

GameEngineImageManager::GameEngineImageManager() 
{
}

GameEngineImageManager::~GameEngineImageManager() 
{

	std::map<std::string, GameEngineImage*>::iterator StartIter = AllRes.begin();
	std::map<std::string, GameEngineImage*>::iterator EndtIter = AllRes.end();

	for (; StartIter != EndtIter; ++StartIter)
	{

		if (nullptr != StartIter->second)
		{
		  delete StartIter->second;
		  StartIter->second = nullptr;
		}

	}
}

GameEngineImage* GameEngineImageManager::Create(const std::string& _Name, float4 _Scale)
{
	if (AllRes.end() != AllRes.find(_Name))
	{
		MsgBoxAssert("�̹� �����ϴ� �̸��� �̹����� �� ������� �߽��ϴ�.");
		return nullptr;
	}
	
	GameEngineImage* NewImage = new GameEngineImage();
	NewImage->SetName(_Name);

	if (false == NewImage->Create(_Scale))
	{
		delete NewImage;
		MsgBoxAssert((_Name + "�̹����� �����ϴµ� �����߽��ϴ�.").c_str());
		return nullptr;
	}

	AllRes.insert(std::make_pair(_Name, NewImage));

	return NewImage;
}
