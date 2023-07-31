#pragma once
#include <iostream>

namespace Lab2
{
	class point
	{
	public:
		//properties
		int x, y, z;
		//methods
		point(int x=0, int y=0, int z=0)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}
		
		friend std::ostream& operator<<(std::ostream& os, const point& pt);
		
		friend bool smaller(point a, point b);
		friend bool bigger(point a, point b);
	};

	std::ostream& operator <<(std::ostream& os, const point& pt)
	{
		os << pt.x << "\t" << pt.y << "\t" << pt.z;
		return os;
	}

	bool smaller (point a, point b)
	{
		if (a.x < b.x)
		{
			return true;
		}
		if (a.x == b.x)
		{	
			if (a.y > b.y)
				return true;
			else if (a.y == b.y && a.z < b.z)
				return true;
		}
		return false;
	}

	bool bigger (point a, point b)
	{
		if (a.x > b.x)
		{
			return true;
		}
		if (a.x == b.x)
		{	
			if (a.y < b.y)
				return true;
			else if (a.y == b.y && a.z > b.z)
				return true;
		}
		return false;
	}

	template <typename T1>
	std::vector<T1> qckSort(std::vector<T1> &a, comp comparison = Smaller, int lft=0, int right=-1)
	{
		if (right < 0)
			right = a.size() - 1;
		if (right - lft <= 1)
			return a;
		int p = (lft + right)/2;
		int i = lft, j = right;
		while (i < j)
		{
			if (comparison == Smaller)
			{
				while (smaller(a[i], a[p]))
					i++;
				while (bigger(a[j], a[p]))
					j--;
			}
			else
			{
				while (bigger(a[i], a[p]))
					i++;
				while (smaller(a[j], a[p]))
					j--;
			}
			
			if (i < j)
				DSA::swap(a[i], a[j]);	
		}
		if (i < right)
			qckSort(a, comparison, i, right);
		if (j > lft)
			qckSort(a, comparison, lft, j);
		return a;
	}
}