#include "Span.hpp"

/**
 * @brief Builds an empty Span with zero capacity.
 */
Span::Span(void) : maxSize(0), numbers() {}

/**
 * @brief Builds a Span with a fixed capacity.
 * @param n - Maximum number of values to store.
 */
Span::Span(unsigned int n) : maxSize(n), numbers() {}

/**
 * @brief Copy-constructs a Span.
 * @param other - Source Span to copy.
 */
Span::Span(const Span& other) : maxSize(other.maxSize), numbers(other.numbers) {}

/**
 * @brief Assigns Span state from another instance.
 * @param other - Source Span.
 * @return Reference to this Span.
 */
Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this->maxSize = other.maxSize;
		this->numbers = other.numbers;
	}
	return *this;
}

/**
 * @brief Destroys the Span instance.
 */
Span::~Span(void) {}

/**
 * @brief Adds one number to the container.
 * @param number - Value to append.
 */
void	Span::addNumber(int number)
{
	if (this->numbers.size() >= this->maxSize)
		throw SpanFullException();
	this->numbers.push_back(number);
}

/**
 * @brief Computes the minimum difference between stored values.
 * Requires at least two numbers.
 * @return Smallest span as unsigned int.
 */
unsigned int	Span::shortestSpan(void) const
{
	std::vector<int>	sortedNumbers;
	unsigned int		shortest;
	unsigned int		currentSpan;
	std::size_t			i;

	if (this->numbers.size() < 2)
		throw NoSpanFoundException();
	sortedNumbers = this->numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	shortest = static_cast<unsigned int>(sortedNumbers[1] - sortedNumbers[0]);
	i = 1;
	while (i < sortedNumbers.size() - 1)
	{
		currentSpan = static_cast<unsigned int>(sortedNumbers[i + 1]
				- sortedNumbers[i]);
		if (currentSpan < shortest)
			shortest = currentSpan;
		++i;
	}
	return shortest;
}

/**
 * @brief Computes the maximum difference between stored values.
 * Requires at least two numbers.
 * @return Largest span as unsigned int.
 */
unsigned int	Span::longestSpan(void) const
{
	int	minValue;
	int	maxValue;

	if (this->numbers.size() < 2)
		throw NoSpanFoundException();
	minValue = *std::min_element(this->numbers.begin(), this->numbers.end());
	maxValue = *std::max_element(this->numbers.begin(), this->numbers.end());
	return static_cast<unsigned int>(maxValue - minValue);
}

/**
 * @brief Returns message for capacity overflow.
 * @return Static exception message.
 */
const char*	Span::SpanFullException::what() const throw()
{
	return "Span is already full";
}

/**
 * @brief Returns message for missing span data.
 * @return Static exception message.
 */
const char*	Span::NoSpanFoundException::what() const throw()
{
	return "No span can be found";
}