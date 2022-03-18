#include "GameEngineImage.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineWindow.h>

// #pragma comment(lib, "msimg32.lib")

GameEngineImage::GameEngineImage() 
	: ImageDC_(nullptr)
{
}

GameEngineImage::~GameEngineImage() 
{
}

bool GameEngineImage::Create(HDC _DC)
{
	ImageDC_ = _DC;
	ImageScaleCheck();
	return true;
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
	HBITMAP CurrentBitMap = (HBITMAP)GetCurrentObject(ImageDC_, OBJ_BITMAP);
	GetObject(BitMap_, sizeof(BITMAP), &Info_);
}

void GameEngineImage::BitCopy(GameEngineImage* _Other)
{
	BitCopy(_Other, { 0, 0 }, { 0, 0 }, _Other->GetScale());
}

void GameEngineImage::BitCopy(GameEngineImage* _Other, const float4& _CopyPos, const float4& _OtherPivot, const float4& _OtherPivotScale)
{
	// �����쿡�� �������ִ� �Ϲ����� dc vs dc�� �����Լ��Դϴ�.
	BitBlt(
		ImageDC_, // ���⿡ �����ض�.
		_CopyPos.ix(), // �� �̹����� �� �κ� x
		_CopyPos.iy(), // �� �̹����� �� �κ� y �� �����ض�
		_OtherPivotScale.ix(), // �� �̹����� �� ũ�⸸ŭ x
		_OtherPivotScale.iy(), // �� �̹����� �� ũ�⸸ŭ y
		_Other->ImageDC_, // �����Ϸ��� �����
		_OtherPivot.ix(), // �����Ϸ��� ����� ������X
		_OtherPivot.iy(),// �����Ϸ��� ����� ������Y
		SRCCOPY // �����϶�� ���
	);
}

