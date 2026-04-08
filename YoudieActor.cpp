#include "YoudieActor.h"

AYoudieActor::AYoudieActor()
{
	TextRenderComponet->SetText("Yot Died");
	X = 200;
	Y = 100;
	TextRenderComponet->ZOrder = 200;
	TextRenderComponet->bIsVisible = false;
}

AYoudieActor::~AYoudieActor()
{
}
