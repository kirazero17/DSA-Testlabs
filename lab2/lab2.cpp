#include <iostream>
#include <vector>
#include <algorithm>
#include <base.h>

//cac ham bai tap
#include <lab2/lab2.h>
#include <lab2/headers/bai1.h>
#include <lab2/headers/bai2.h>
#include <lab2/headers/bai3.h>
#include <lab2/headers/bai4.h>

int Lab2()
{
	int arr[] = {5, 1, 16, 2, 3, 1, 4, 8, 7};
	//bai 1
	{
		selSort<int>(arr);
		DSA::printArr(arr);
	}
	//bai 2
	{
		insSort<int>(arr);
		DSA::printArr(arr);
	}
	//bai3
	{
		qckSort<int>(arr);
		DSA::printArr(arr);
	}
	//bai4
	{
		using std::cin;
		
		int N;
		cin >> N;
		std::vector<point> pt;
		int x,y,z;

		for (int i = 1; i <= N; i++)
		{
			cin >> x >> y >> z;
			pt.push_back(point(x, y, z));
		}
		
		//std::sort (pt.begin(), pt.end(), smaller);
		pt = qckSort<point>(pt);
		DSA::printVct(pt);
	}
	return 0;
}
