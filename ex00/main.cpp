#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

static void testVector()
{
	std::vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	try
	{
		std::vector<int>::iterator it = easyfind(v, 30);
		std::cout << "[vector] found: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "[vector] error: " << e.what() << std::endl;
	}

	try
	{
		easyfind(v, 999);
		std::cout << "[vector] found 999 (unexpected)" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "[vector] error: " << e.what() << std::endl;
	}
}

static void testList()
{
	std::list<int> lst;

	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);

	try
	{
		std::list<int>::iterator it = easyfind(lst, 2);
		std::cout << "[list] found: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "[list] error: " << e.what() << std::endl;
	}
}

int main()
{
	testVector();
	testList();
	return 0;
}