#include "GameEnginePath.h"

GameEnginePath::GameEnginePath() 
{
}

GameEnginePath::GameEnginePath(const std::filesystem::path& _Path)
	: Path_(_Path)
{

}

GameEnginePath::~GameEnginePath() 
{
}

void GameEnginePath::SetCurrentPath()
{
	Path_ = std::filesystem::current_path();
}

bool GameEnginePath::IsExits()
{
	return std::filesystem::exists(Path_);
}

std::string GameEnginePath::GetExtension()
{
	// 확장자가 없으면 디렉토리라고 할수 없다

	return Path_.extension().string();
}

std::string GameEnginePath::GetFileName()
{
	return Path_.filename().string();
}

std::string GameEnginePath::GetFullPath()
{
	return Path_.string();
}