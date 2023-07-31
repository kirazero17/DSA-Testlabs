#pragma once

#include <base.h>

namespace Lab2
{
	template <typename T, int N>
	void selSort(T (&a)[N])
	{
		for (int min = 0; min < N; min++)
		{
			for (int j = min + 1; j < N; j++)
			{
				if (a[j] < a[min])
					DSA::swap(a[j], a[min]);
			}
		}
	}
}