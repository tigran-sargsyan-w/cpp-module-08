#include <iostream>
#include <list>
#include "MutantStack.hpp"

/**
 * @brief Runs the official subject example.
 * Demonstrates stack operations and iteration.
 */
static void subjectTest(void)
{
	std::cout << "=== Subject test ===" << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);
	(void)s;
}

/**
 * @brief Compares MutantStack behavior with std::list.
 * Prints both sequences after similar operations.
 */
static void listComparisonTest(void)
{
	std::cout << "\n=== Comparison with std::list ===" << std::endl;

	MutantStack<int>	mstack;
	std::list<int>		lst;

	mstack.push(5);
	mstack.push(17);
	mstack.pop();
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	lst.push_back(5);
	lst.push_back(17);
	lst.pop_back();
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::cout << "MutantStack: ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "std::list:   ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

/**
 * @brief Validates copy constructor and assignment.
 * Prints original and copied stacks.
 */
static void copyTest(void)
{
	std::cout << "\n=== Copy test ===" << std::endl;

	MutantStack<int> original;
	original.push(10);
	original.push(20);
	original.push(30);

	MutantStack<int> copy(original);
	MutantStack<int> assigned;
	assigned = original;

	std::cout << "Original: ";
	for (MutantStack<int>::iterator it = original.begin(); it != original.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Copy:     ";
	for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Assigned: ";
	for (MutantStack<int>::iterator it = assigned.begin(); it != assigned.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

/**
 * @brief Demonstrates reverse iterator traversal.
 * Prints stack content in reverse order.
 */
static void reverseIteratorTest(void)
{
	std::cout << "\n=== Reverse iterator test ===" << std::endl;

	MutantStack<int> mstack;
	mstack.push(1);
	mstack.push(2);
	mstack.push(3);
	mstack.push(4);

	for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

/**
 * @brief Program entry point for ex02 tests.
 * Executes all MutantStack scenarios.
 * @return Exit status code.
 */
int main(void)
{
	subjectTest();
	listComparisonTest();
	copyTest();
	reverseIteratorTest();
	return (0);
}