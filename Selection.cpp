#include "Selection.h"
Selection::Selection()
{
}
Selection::~Selection()
{
}

void Selection::Sort(int* data, int InSize)
{
	int Array;
	for (int i = 0; i < InSize; i++)
	{
		for (int j = 0; j < InSize; j++)
		{
			if (data[i] < data[j])
			{
				Array = data[i];
				data[i] = data[j];
				data[j] = Array;
			}
		}
	}
}
