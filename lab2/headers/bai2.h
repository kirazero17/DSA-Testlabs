#pragma once

#include <base.h>

namespace Lab2
{
	template <typename T, int N>
	void insSort(T (&a)[N])
	{
		for (int i = 1; i < N; i++)
		{
			for (int j = i; j > 0; j--)
			{
				if (a[j] < a[j-1])
					DSA::swap(a[j], a[j-1]);
			}
		}
	}
}