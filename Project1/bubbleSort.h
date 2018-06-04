#pragma once
#include "Headers.h"

template <typename T>
class bubbleSort {
public:
	static void sort(T *a, int size)
	{
		int j;
		for (int i = 0; i < size; i++)
		{
			for (j = (size - 1); j > i; j--)
			{
				if (a[j - 1] > a[j])
				{
					T temp = a[j - 1];
					a[j - 1] = a[j];
					a[j] = temp;
				}
			}
			cout << a[j] << "\t";
		}
	}



};