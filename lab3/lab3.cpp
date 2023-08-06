#include <iostream>
#include <string>

#include <lab3/lab3.h>
#include <lab3/headers/bai1.h>
#include <lab3/headers/bai2n3.h>
#include <lab3/headers/bai4.h>

int lab3()
{
	using namespace Lab3; 
	
	//Bai 1
	/**
	{
		using namespace Bai1;
		
		std::string ten;
		float dtb;
		
		List lophoc;
		//1b
		do
		{
			ten = "_";
			std::getline(std::cin, ten);
			std::cin>>dtb;
			std::cin.sync();
		}
		while (lophoc.push(ten, dtb));
		//1c
		std::cout << std::boolalpha; 
		std::cout << lophoc.find("Nam") << std::endl;
		std::cout << lophoc.find("Le") << std::endl << std::endl;
		//1d
		lophoc.del(20520002);
		//1f-1e
		
		//1f-1g
		lophoc.sort();
		lophoc.PrintAll();
	}
	 **/
	
	std::cout << std::endl;

	//Bai 2
	{
		using namespace Bai2n3;
		int N, v;
		List numlist;
		std::cin >> N;
		for (int i = 1; i <= N; i++)
		{
			std::cin >> v;
			numlist.add(v);
		}
		std::cin >> v;
		numlist.add(v);
		numlist.PrintAll();
	}
	
	std::cout << std::endl;
	
	//Bai 3
	{
		using namespace Bai2n3;
		int N, v;
		List numlist;
		std::cin >> N;
		for (int i = 1; i <= N; i++)
		{
			std::cin >> v;
			numlist.add(v);
		}
		numlist.Reverse();
		numlist.PrintAll();
	}
	
	std::cout << std::endl;
	
	//Bai 4
	{
		using namespace Bai4;
		int N;
		std::cin >> N;
	}
	return 0;
}