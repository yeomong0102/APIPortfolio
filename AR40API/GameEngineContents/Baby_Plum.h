#pragma once

// Ό³Έν :
class Baby_Plum
{
public:
	// constrcuter destructer
	Baby_Plum();
	~Baby_Plum();

	// delete Function
	Baby_Plum(const Baby_Plum& _Other) = delete;
	Baby_Plum(Baby_Plum&& _Other) noexcept = delete;
	Baby_Plum& operator=(const Baby_Plum& _Other) = delete;
	Baby_Plum& operator=(Baby_Plum&& _Other) noexcept = delete;

protected:

private:

};

