#pragma once

// Ό³Έν :
class Soy_Milk
{
public:
	// constrcuter destructer
	Soy_Milk();
	~Soy_Milk();

	// delete Function
	Soy_Milk(const Soy_Milk& _Other) = delete;
	Soy_Milk(Soy_Milk&& _Other) noexcept = delete;
	Soy_Milk& operator=(const Soy_Milk& _Other) = delete;
	Soy_Milk& operator=(Soy_Milk&& _Other) noexcept = delete;

protected:

private:

};

