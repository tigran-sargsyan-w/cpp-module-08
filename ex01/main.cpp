#include <iostream>
#include <vector>
#include "Span.hpp"

/**
 * @brief Runs the standard subject scenario.
 * Adds numbers and prints shortest and longest spans.
 */
static void	subjectTest(void)
{
	std::cout << "=== Subject test ===" << std::endl;

	Span sp(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

/**
 * @brief Verifies exception handling paths.
 * Triggers errors for missing span and full storage.
 */
static void	exceptionTest(void)
{
	std::cout << "=== Exception test ===" << std::endl;

	try
	{
		Span sp(2);
		sp.addNumber(10);
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Span sp(2);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
}

/**
 * @brief Tests bulk insertion through iterator range.
 * Adds a vector range and prints computed spans.
 */
static void	rangeTest(void)
{
	std::cout << "=== Range test ===" << std::endl;

	std::vector<int>	values;
	Span				sp(10);

	values.push_back(100);
	values.push_back(103);
	values.push_back(105);
	values.push_back(110);

	sp.addRange(values.begin(), values.end());

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

/**
 * @brief Stress test with many inserted values.
 * Fills Span with 10000 numbers and prints spans.
 */
static void	bigTest(void)
{
	std::cout << "=== Big test (10000 numbers) ===" << std::endl;

	Span sp(10000);
	int i;

	i = 0;
	while (i < 10000)
	{
		sp.addNumber(i * 2);
		++i;
	}

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

/**
 * @brief Program entry point for ex01 tests.
 * Executes all Span test scenarios.
 * @return Exit status code.
 */
int	main(void)
{
	subjectTest();
	exceptionTest();
	rangeTest();
	bigTest();
	return 0;
}