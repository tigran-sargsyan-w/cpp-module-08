#include "Span.hpp"

Span::Span(void) : maxSize(0), numbers() {}

Span::Span(unsigned int n) : maxSize(n), numbers() {}

Span::Span(const Span& other) : maxSize(other.maxSize), numbers(other.numbers) {}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this->maxSize = other.maxSize;
		this->numbers = other.numbers;
	}
	return *this;
}

Span::~Span(void) {}

void	Span::addNumber(int number)
{
	if (this->numbers.size() >= this->maxSize)
		throw SpanFullException();
	this->numbers.push_back(number);
}

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

const char*	Span::SpanFullException::what() const throw()
{
	return "Span is already full";
}

const char*	Span::NoSpanFoundException::what() const throw()
{
	return "No span can be found";
}