#pragma once

// Ό³Έν :
class Grotesk
{
public:
	// constrcuter destructer
	Grotesk();
	~Grotesk();

	// delete Function
	Grotesk(const Grotesk& _Other) = delete;
	Grotesk(Grotesk&& _Other) noexcept = delete;
	Grotesk& operator=(const Grotesk& _Other) = delete;
	Grotesk& operator=(Grotesk&& _Other) noexcept = delete;

protected:

private:

};

