#pragma once

// Ό³Έν :
class Flys
{
public:
	// constrcuter destructer
	Flys();
	~Flys();

	// delete Function
	Flys(const Flys& _Other) = delete;
	Flys(Flys&& _Other) noexcept = delete;
	Flys& operator=(const Flys& _Other) = delete;
	Flys& operator=(Flys&& _Other) noexcept = delete;

protected:

private:

};

