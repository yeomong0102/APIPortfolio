#include "PlayLevel.h"
#include "Player.h"
#include "Flys.h"

enum class OREDER
{
	BACKGROUND,
	PLAYER,
	MONSTER,
	UI
};

PlayLevel::PlayLevel()
{
}

PlayLevel::~PlayLevel()
{
}

void PlayLevel::Loading()
{

}

void PlayLevel::Update()
{

}
void PlayLevel::LevelChangeStart()
{
	CreateActor<Player>((int)OREDER::PLAYER);
	CreateActor<Flys>((int)OREDER::MONSTER);
}