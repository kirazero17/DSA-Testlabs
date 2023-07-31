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

int lab2()
{
	int arr[] = {5, 1, 16, 2, 3, 1, 4, 8, 7};
	//bai 1
	{
		Lab2::selSort<int>(arr);
		DSA::printArr(arr);
	}
	//bai 2
	{
		Lab2::insSort<int>(arr);
		DSA::printArr(arr);
	}
	//bai3
	{
		Lab2::qckSort<int>(arr);
		DSA::printArr(arr);
	}
	//bai4
	{
		using std::cin;
		
		int N;
		cin >> N;
		std::vector<Lab2::point> pt;
		int x,y,z;

		for (int i = 1; i <= N; i++)
		{
			cin >> x >> y >> z;
			pt.push_back(Lab2::point(x, y, z));
		}
		
		//std::sort (pt.begin(), pt.end(), smaller);
		pt = Lab2::qckSort<Lab2::point>(pt);
		DSA::printVct(pt);
	}
	return 0;
}
