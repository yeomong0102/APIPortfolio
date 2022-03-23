#pragma once

// Ό³Έν :
class Demon_Baby
{
public:
	// constrcuter destructer
	Demon_Baby();
	~Demon_Baby();

	// delete Function
	Demon_Baby(const Demon_Baby& _Other) = delete;
	Demon_Baby(Demon_Baby&& _Other) noexcept = delete;
	Demon_Baby& operator=(const Demon_Baby& _Other) = delete;
	Demon_Baby& operator=(Demon_Baby&& _Other) noexcept = delete;

protected:

private:

};

