#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>
# include <algorithm>

class Span
{
	private:
		unsigned int		maxSize;
		std::vector<int>	numbers;

	public:
		Span(void);
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span(void);

		void	addNumber(int number);

		template <typename InputIterator>
		void	addRange(InputIterator begin, InputIterator end)
		{
			unsigned int	rangeSize;

			rangeSize = static_cast<unsigned int>(std::distance(begin, end));
			if (this->numbers.size() + rangeSize > this->maxSize)
				throw SpanFullException();
			this->numbers.insert(this->numbers.end(), begin, end);
		}

		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;

		class SpanFullException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class NoSpanFoundException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif