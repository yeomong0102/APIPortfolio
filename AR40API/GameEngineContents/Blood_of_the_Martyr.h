#pragma once

// Ό³Έν :
class Blood_of_the_Martyr
{
public:
	// constrcuter destructer
	Blood_of_the_Martyr();
	~Blood_of_the_Martyr();

	// delete Function
	Blood_of_the_Martyr(const Blood_of_the_Martyr& _Other) = delete;
	Blood_of_the_Martyr(Blood_of_the_Martyr&& _Other) noexcept = delete;
	Blood_of_the_Martyr& operator=(const Blood_of_the_Martyr& _Other) = delete;
	Blood_of_the_Martyr& operator=(Blood_of_the_Martyr&& _Other) noexcept = delete;

protected:

private:

};

