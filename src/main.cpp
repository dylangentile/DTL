#include <iostream>
#include <vector>
#include "vector.h"


int main()
{

	dtl::vector_int v(4,4,1);
	for(int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	std::cout << "\nold way:\n";
	for(unsigned i = 0; i < v.size(); i++)
	{
		
		std::cout << v.at(i) << "\n";
	}
	std::cout << "\nnew way:\n";
	for(int *it = v.begin(); it != v.end(); it++)
	{
		std::cout << *it << "\n";
	}

/*
	std::cout << "\n\n";

	for(unsigned i = v.size(); i > 0; i--)
	{
	
		std::cout << "\nPopping: '" << v.at(i - 1) << "'";

		v.pop_back();

	}

*/
	v.clear();

	return 0;
}