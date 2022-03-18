#pragma once
#include <GameEngine/GameEngine.h>

// Ό³Έν :

class IssacGame : public GameEngine
{
public:
	// constrcuter destructer
	IssacGame();
	~IssacGame();

	// delete Function
	IssacGame(const IssacGame& _Other) = delete;
	IssacGame(IssacGame&& _Other) noexcept = delete;
	IssacGame& operator=(const IssacGame& _Other) = delete;
	IssacGame& operator=(IssacGame&& _Other) noexcept = delete;

	void GameInit() override;
	void GameLoop() override;
	void GameEnd() override;

protected:
	
private:

};

