#include "TextRenderActor.h"
ATextRenderActor::ATextRenderActor()
{
	TextRenderComponet = CreateDefaultSubobject<UTextRenderComponent>("TextRender");
}
ATextRenderActor::~ATextRenderActor()
{
}
