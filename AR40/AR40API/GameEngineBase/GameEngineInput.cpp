#include "GameEngineInput.h"
#include "GameEngineDebug.h"
#include "GameEngineString.h"

/// //////////////////////////////////////////
void GameEngineInput::GameEngineKey::Update()
{
	if (true == KeyCheck())  // 눌렀다
	{
		if (true == Free_)  // 방금전까지 Free가 true 그러면 처음눌렀다는 뜻
		{
			Down_ = true;
			Press_ = true;
			Up_ = false;
			Free_ = false;
		}
		else if (true == Press_) // 방금전까지 Press_ == true 그러면 쭉누르고 있다는 뜻
		{
			Down_ = false;
			Press_ = true;
			Up_ = false;
			Free_ = false;
		}
	}
	else // 키를 안눌럿음 즉 방금전까지 누르고 있었다
	{
		if (true == Press_)
		{
			Down_ = false;
			Press_ = false;
			Up_ = true;
			Free_ = false;
		}
		else if (true == Up_)
		{
			Down_ = false;
			Press_ = false;
			Up_ = false;
			Free_ = true;
		}
	}
}
/// //////////////////////////////////////////

GameEngineInput* GameEngineInput::Inst_ = new GameEngineInput();

GameEngineInput::GameEngineInput() 
{
}

GameEngineInput::~GameEngineInput() 
{
}

bool GameEngineInput::IsKey(const std::string& _Name)
{
	if (AllInputKey_.end() != AllInputKey_.find(_Name))
	{
		return true;
	}

	return false;
}

void GameEngineInput::CreateKey(const std::string& _Name, int _Key)
{
	std::string UpperKey = GameEngineString::ToUpperReturn(_Name);

	if (AllInputKey_.end() != AllInputKey_.find(UpperKey))
	{
		MsgBoxAssert("이미 존재하는 이름의 키를 또 만들려고 했습니다.");
		return;
	}


	if ('a' <= _Key && 'z' >= _Key)
	{
		_Key = std::toupper(_Key);
	}

	AllInputKey_.insert(std::make_pair(UpperKey, GameEngineKey()));
	AllInputKey_[UpperKey].Key_ = _Key;
	AllInputKey_[UpperKey].Reset();

}

void GameEngineInput::Update()
{
	std::map<std::string, GameEngineKey>::iterator KeyUpdateStart = AllInputKey_.begin();
	std::map<std::string, GameEngineKey>::iterator KeyUpdateEnd = AllInputKey_.end();

	for (; KeyUpdateStart != KeyUpdateEnd; ++KeyUpdateStart)
	{
		GameEngineKey& CurrentKey = KeyUpdateStart->second;
		
		CurrentKey.Update();
	}
}

bool GameEngineInput::IsDown(const std::string& _Name)
{
	std::string UpperKey = GameEngineString::ToUpperReturn(_Name);

	if (AllInputKey_.end() == AllInputKey_.find(UpperKey))
	{
		MsgBoxAssert("이미 존재하는 이름의 키를 또 만들려고 했습니다.");
		return false;
	}

	return AllInputKey_[UpperKey].Down_;
}
bool GameEngineInput::IsUp(const std::string& _Name)
{
	std::string UpperKey = GameEngineString::ToUpperReturn(_Name);

	if (AllInputKey_.end() == AllInputKey_.find(UpperKey))
	{
		MsgBoxAssert("이미 존재하는 이름의 키를 또 만들려고 했습니다.");
		return false;
	}

	return AllInputKey_[UpperKey].Up_;
}
bool GameEngineInput::IsPress(const std::string& _Name)
{
	std::string UpperKey = GameEngineString::ToUpperReturn(_Name);

	if (AllInputKey_.end() == AllInputKey_.find(UpperKey))
	{
		MsgBoxAssert("이미 존재하는 이름의 키를 또 만들려고 했습니다.");
		return false;
	}

	return AllInputKey_[UpperKey].Press_;
}
bool GameEngineInput::IsFree(const std::string& _Name)
{
	std::string UpperKey = GameEngineString::ToUpperReturn(_Name);

	if (AllInputKey_.end() == AllInputKey_.find(UpperKey))
	{
		MsgBoxAssert("이미 존재하는 이름의 키를 또 만들려고 했습니다.");
		return false;
	}

	return AllInputKey_[UpperKey].Free_;
}

	 