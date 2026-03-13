#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		typedef typename std::stack<T, Container>::container_type	container_type;
		typedef typename container_type::iterator					iterator;
		typedef typename container_type::const_iterator				const_iterator;
		typedef typename container_type::reverse_iterator			reverse_iterator;
		typedef typename container_type::const_reverse_iterator		const_reverse_iterator;

		MutantStack(void);
		MutantStack(const MutantStack& other);
		~MutantStack(void);

		MutantStack& operator=(const MutantStack& other);

		iterator begin(void);
		iterator end(void);

		const_iterator begin(void) const;
		const_iterator end(void) const;

		reverse_iterator rbegin(void);
		reverse_iterator rend(void);

		const_reverse_iterator rbegin(void) const;
		const_reverse_iterator rend(void) const;
};

#include "MutantStack.tpp"

#endif