#pragma once

#include <vector>
#include <iostream>

enum comp //cho viec sap xep
{
	Greater = false,
	Smaller = true
};

enum search
{
	equal,
	greater,
	smaller
};

namespace DSA
{
	template <typename T>
	void swap(T &a, T &b)
	{
		T i = a;
		a = b;
		b = i;
	}

	template <typename T, int N>
	void printArr(T (&a)[N])
	{
		for (int i = 0; i < N; i++)
		{
			std::cout << a[i];
			if (i != N - 1)
			{
				std::cout << "  ";
				continue;
			}
			std::cout << std::endl;
		}
	}

	template <typename T>
	void printVct(const std::vector<T> &a)
	{
		for (int i = 0; (long long unsigned)i < a.size(); i++)
		{
			std::cout << "\t" << a[i] << std::endl;
		}
	}
}