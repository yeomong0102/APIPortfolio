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
		MsgBoxAssert("크기가 0인 이미지를 제작하려고 했습니다.")
	}

	BitMap_ = CreateCompatibleBitmap(GameEngineWindow::GetHDC(), _Scale.ix(), _Scale.iy());

	// 그릴수 있는 권한이 없어서 비어있어야 하는게 이론이지만
	// 실제로는 뭔가 하나 붙어있다

	// DC는 2차원배열에 간섭할수있는 권한인데
	// DC는 HBITMAP이 없으면 아무의미 없어서 임의로 1,1의 HBITMAP을 붙여준다
	ImageDC_ = CreateCompatibleDC(nullptr);

	if (nullptr == ImageDC_)
	{
		MsgBoxAssert("ImageDc 생성에 실패했습니다.");
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
	// 윈도우에서 지원해주는 일반적인 dc vs dc의 복사함수입니다.
	BitBlt(
		ImageDC_, // 여기에 복사해라.
		_CopyPos.ix(), // 내 이미지의 이 부분 x
		_CopyPos.iy(), // 내 이미지의 이 부분 y 에 복사해라
		_OtherPivotScale.ix(), // 내 이미지의 이 크기만큼 x
		_OtherPivotScale.iy(), // 내 이미지의 이 크기만큼 y
		_Other->ImageDC_, // 복사하려는 대상은
		_OtherPivot.ix(), // 복사하려는 대상의 시작점X
		_OtherPivot.iy(),// 복사하려는 대상의 시작점Y
		SRCCOPY // 복사하라는 명령
	);
}

