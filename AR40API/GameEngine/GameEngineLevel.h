#pragma once
#include "GameEngineBase/GameEngineNameObject.h"
#include <map>
#include <list>


// 설명 :
class GameEngine;
class GameEngineActor;
class GameEngineLevel : public GameEngineNameObject
{
	friend GameEngine;
public:
	// constrcuter destructer
	GameEngineLevel();

	virtual ~GameEngineLevel();

	// delete Function
	GameEngineLevel(const GameEngineLevel& _Other) = delete;
	GameEngineLevel(GameEngineLevel&& _Other) noexcept = delete;
	GameEngineLevel& operator=(const GameEngineLevel& _Other) = delete;
	GameEngineLevel& operator=(GameEngineLevel&& _Other) noexcept = delete;

protected:
	// 시점함수
	// 만들어지면서 리소스나 액터를 만들때 써라
	virtual void Loading() = 0;
	// 이 레벨이 현재 레벨일때 해야할일을 실행한다.
	virtual void Update() = 0;
	// Current레벨 => Next레벨로 이전할때 현재레벨이 실행하는 함수.
	virtual void LevelChangeStart() {}
	// Current레벨 => Next레벨로 이전할때 이전레벨이 실행하는 함수.
	virtual void LevelChangeEnd() {}

	template<typename ActorType>
	ActorType* CreateActor(const std::string& _Name, int _Order)
	{
		ActorType* NewActor = new ActorType();
		GameEngineActor* StartActor = NewActor;

		NewActor->SetName(_Name);
		NewActor->SetLevel(this);

		StartActor->Start();

		std::list<GameEngineActor*>& Group = AllActor_[_Order];
		Group.push_back(NewActor);


		return nullptr;
	}

private:
	// std::vector로 관리하는게 더 좋다고 생각합니다.
	std::map<int, std::list<GameEngineActor*>> AllActor_;

	// string으로 이름으로 찾는건 최악의 수다
	// std::map<std::string, std::list<GameEngineActor*>> AllActor_;

	void ActorUpdata();
	void ActorRender();
};

