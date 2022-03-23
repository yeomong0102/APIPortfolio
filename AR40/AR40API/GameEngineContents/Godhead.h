#pragma once

// Ό³Έν :
class Godhead
{
public:
	// constrcuter destructer
	Godhead();
	~Godhead();

	// delete Function
	Godhead(const Godhead& _Other) = delete;
	Godhead(Godhead&& _Other) noexcept = delete;
	Godhead& operator=(const Godhead& _Other) = delete;
	Godhead& operator=(Godhead&& _Other) noexcept = delete;

protected:

private:

};

