#pragma once


class IRenderableComponent
{
public:
	virtual void Render() = 0;

	int ZOrder = 0;

	int bIsVisible : 1;
};


