#pragma once

// Ό³Έν :
class Basement
{
public:
	// constrcuter destructer
	Basement();
	~Basement();

	// delete Function
	Basement(const Basement& _Other) = delete;
	Basement(Basement&& _Other) noexcept = delete;
	Basement& operator=(const Basement& _Other) = delete;
	Basement& operator=(Basement&& _Other) noexcept = delete;

protected:

private:

};

