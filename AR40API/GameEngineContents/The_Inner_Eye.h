#pragma once

// Ό³Έν :
class The_Inner_Eye
{
public:
	// constrcuter destructer
	The_Inner_Eye();
	~The_Inner_Eye();

	// delete Function
	The_Inner_Eye(const The_Inner_Eye& _Other) = delete;
	The_Inner_Eye(The_Inner_Eye&& _Other) noexcept = delete;
	The_Inner_Eye& operator=(const The_Inner_Eye& _Other) = delete;
	The_Inner_Eye& operator=(The_Inner_Eye&& _Other) noexcept = delete;

protected:

private:

};

