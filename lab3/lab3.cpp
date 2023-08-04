#include <iostream>
#include <string>

#include <lab3/lab3.h>
#include <lab3/headers/bai1.h>
#include <lab3/headers/bai2.h>

int lab3()
{
	using namespace Lab3; 
	
	//Bai 1
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
	
	std::cout << std::endl;

	//Bai 2
	{
		
	}
	
	std::cout << std::endl;
	
	//Bai 3
	{
		
	}
	
	std::cout << std::endl;
	
	//Bai 4
	{
		
	}
	return 0;
}