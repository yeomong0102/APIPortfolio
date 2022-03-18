#pragma once
#include "GameEngineBase/GameEngineNameObject.h"
#include <map>
#include <list>


// ���� :
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
	// �����Լ�
	// ��������鼭 ���ҽ��� ���͸� ���鶧 ���
	virtual void Loading() = 0;
	// �� ������ ���� �����϶� �ؾ������� �����Ѵ�.
	virtual void Update() = 0;
	// Current���� => Next������ �����Ҷ� ���緹���� �����ϴ� �Լ�.
	virtual void LevelChangeStart() {}
	// Current���� => Next������ �����Ҷ� ���������� �����ϴ� �Լ�.
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
	// std::vector�� �����ϴ°� �� ���ٰ� �����մϴ�.
	std::map<int, std::list<GameEngineActor*>> AllActor_;

	// string���� �̸����� ã�°� �־��� ����
	// std::map<std::string, std::list<GameEngineActor*>> AllActor_;

	void ActorUpdata();
	void ActorRender();
};

