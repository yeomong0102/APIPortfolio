#pragma once

// Ό³Έν :
class Meat
{
public:
	// constrcuter destructer
	Meat();
	~Meat();

	// delete Function
	Meat(const Meat& _Other) = delete;
	Meat(Meat&& _Other) noexcept = delete;
	Meat& operator=(const Meat& _Other) = delete;
	Meat& operator=(Meat&& _Other) noexcept = delete;

protected:

private:

};

