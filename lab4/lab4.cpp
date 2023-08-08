#include <lab4/lab4.h>
#include <iostream>

int lab4()
{
	using namespace Lab4;
	//Bai 1
	BSTree tree;
	int N, v;
	std::cin >> N;
	for (int i = 1; i <= N; i++)
	{
		std::cin >> v;
		tree.AddNode(v);
	}
	
	std::cout << std::boolalpha;
	std::cout << "Searching value (4): " << tree.Search(4) << std::endl;
	std::cout << "Deleting value (4): " << tree.Delete(4) << std::endl;
	
	//Bai 2
	std::cout << "Tree height: " << tree.Height() << std::endl;

	return 0;
}