#include "Flys.h"

Flys::Flys() 
{
}

Flys::~Flys() 
{
}

void Flys::Start()
{
	SetPosition({ 640, 600 });
	SetScale({ 25, 25 });
}

void Flys::Render()
{
	DebugRectRender();
}