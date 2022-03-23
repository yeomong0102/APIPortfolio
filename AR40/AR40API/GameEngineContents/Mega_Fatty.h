#pragma once

// Ό³Έν :
class Mega_Fatty
{
public:
	// constrcuter destructer
	Mega_Fatty();
	~Mega_Fatty();

	// delete Function
	Mega_Fatty(const Mega_Fatty& _Other) = delete;
	Mega_Fatty(Mega_Fatty&& _Other) noexcept = delete;
	Mega_Fatty& operator=(const Mega_Fatty& _Other) = delete;
	Mega_Fatty& operator=(Mega_Fatty&& _Other) noexcept = delete;

protected:

private:

};

