#pragma once
#include <base.h>
#include <vector>

template <typename T, int N>
int qckSort(T (&a)[N], comp comparison = Smaller, int lft=0, int right=N-1)
{
	T p = a[(lft + right)/2];
	int i = lft, j = right;
	while (i < j)
	{
		if (comparison == Smaller)
		{
			while ((a[i] <= p))
				i++;
			while ((a[j] >= p))
				j--;
		}
		else
		{
			while ((a[i] >= p))
				i++;
			while ((a[j] <= p))
				j--;
		}

		if (i < j)
			DSA::swap(a[i], a[j]);
	}
	if (i < right)
		qckSort(a, comparison, i, right);
	if (j > lft)
		qckSort(a, comparison, lft, j);
	return 0;
}