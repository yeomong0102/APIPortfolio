#pragma once

// Ό³Έν :
class Doors
{
public:
	// constrcuter destructer
	Doors();
	~Doors();

	// delete Function
	Doors(const Doors& _Other) = delete;
	Doors(Doors&& _Other) noexcept = delete;
	Doors& operator=(const Doors& _Other) = delete;
	Doors& operator=(Doors&& _Other) noexcept = delete;

protected:

private:

};

