#include <Windows.h>

#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineContents/IssacGame.h>


int __stdcall WinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ char* lpCmdLine,
    _In_ int       nCmdShow)
{

    // GameEngineBase의 cpp까지 모르기때문에
    /*

    GameEngineWindow::Destroy();
    MyGame.GameEnd();*/

    GameEngine::Start<IssacGame>();
}