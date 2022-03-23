#pragma once

// Ό³Έν :
class Spiders
{
public:
	// constrcuter destructer
	Spiders();
	~Spiders();

	// delete Function
	Spiders(const Spiders& _Other) = delete;
	Spiders(Spiders&& _Other) noexcept = delete;
	Spiders& operator=(const Spiders& _Other) = delete;
	Spiders& operator=(Spiders&& _Other) noexcept = delete;

protected:

private:

};

