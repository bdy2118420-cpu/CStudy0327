#include "Selection.h"
Selection::Selection()
{
}
Selection::~Selection()
{
}

void Selection::Sort(int* data)
{
	int Array;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
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

void Selection::Sort(float* data)
{
	float Array;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
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

void Selection::Sort(char* data)
{
	char Array;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
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

void Selection::Sort(double* data)
{
	double Array;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
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
