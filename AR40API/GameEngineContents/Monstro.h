#pragma once

// ���� :
class Monstro
{
public:
	// constrcuter destructer
	Monstro();
	~Monstro();

	// delete Function
	Monstro(const Monstro& _Other) = delete;
	Monstro(Monstro&& _Other) noexcept = delete;
	Monstro& operator=(const Monstro& _Other) = delete;
	Monstro& operator=(Monstro&& _Other) noexcept = delete;

protected:

private:

};

