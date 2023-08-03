#include <iostream>
#include <string>

#include <lab3/lab3.h>
#include <lab3/headers/bai1.h>

int lab3()
{
	using namespace Lab3; 
	{
		using namespace Bai1;
		
		std::string ten;
		float dtb;
		
		List lophoc;
		do
		{
			ten = "_";
			std::getline(std::cin, ten);
			std::cin>>dtb;
			std::cin.sync();
		}
		while (lophoc.push(ten, dtb));
		lophoc.del(20520002);
		lophoc.sort();
		lophoc.PrintAll();
	}
	return 0;
}