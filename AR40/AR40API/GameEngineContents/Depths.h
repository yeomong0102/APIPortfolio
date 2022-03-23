#pragma once

// Ό³Έν :
class Depths
{
public:
	// constrcuter destructer
	Depths();
	~Depths();

	// delete Function
	Depths(const Depths& _Other) = delete;
	Depths(Depths&& _Other) noexcept = delete;
	Depths& operator=(const Depths& _Other) = delete;
	Depths& operator=(Depths&& _Other) noexcept = delete;

protected:

private:

};

