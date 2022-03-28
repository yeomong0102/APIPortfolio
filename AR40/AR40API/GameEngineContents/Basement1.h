#pragma once

// Ό³Έν :
class Basement1
{
public:
	// constrcuter destructer
	Basement1();
	~Basement1();

	// delete Function
	Basement1(const Basement1& _Other) = delete;
	Basement1(Basement1&& _Other) noexcept = delete;
	Basement1& operator=(const Basement1& _Other) = delete;
	Basement1& operator=(Basement1&& _Other) noexcept = delete;

protected:

private:

};

