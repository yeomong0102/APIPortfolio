#pragma once

// Ό³Έν :
class Brimstone
{
public:
	// constrcuter destructer
	Brimstone();
	~Brimstone();

	// delete Function
	Brimstone(const Brimstone& _Other) = delete;
	Brimstone(Brimstone&& _Other) noexcept = delete;
	Brimstone& operator=(const Brimstone& _Other) = delete;
	Brimstone& operator=(Brimstone&& _Other) noexcept = delete;

protected:

private:

};

