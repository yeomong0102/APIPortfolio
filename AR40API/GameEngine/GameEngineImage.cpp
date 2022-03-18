#include "GameEngineImage.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineWindow.h>

GameEngineImage::GameEngineImage() 
{
}

GameEngineImage::~GameEngineImage() 
{
}

bool GameEngineImage::Create(float4 _Scale)
{
	if (true == _Scale.IsZero2D())
	{
		MsgBoxAssert("ũ�Ⱑ 0�� �̹����� �����Ϸ��� �߽��ϴ�.")
	}

	BitMap_ = CreateCompatibleBitmap(GameEngineWindow::GetHDC(), _Scale.ix(), _Scale.iy());

	// �׸��� �ִ� ������ ��� ����־�� �ϴ°� �̷�������
	// �����δ� ���� �ϳ� �پ��ִ�

	// DC�� 2�����迭�� �����Ҽ��ִ� �����ε�
	// DC�� HBITMAP�� ������ �ƹ��ǹ� ��� ���Ƿ� 1,1�� HBITMAP�� �ٿ��ش�
	ImageDC_ = CreateCompatibleDC(nullptr);

	if (nullptr == ImageDC_)
	{
		MsgBoxAssert("ImageDc ������ �����߽��ϴ�.");
	}

	OldBitMap_ = (HBITMAP)SelectObject(ImageDC_, BitMap_);

	ImageScaleCheck();

	return true;
}

void GameEngineImage::ImageScaleCheck()
{
	GetObject(BitMap_, sizeof(BITMAP), &Info_);
}

