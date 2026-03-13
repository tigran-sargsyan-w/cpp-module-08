/**
 * @brief Constructs an empty MutantStack.
 */
template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(void) : std::stack<T, Container>() {}

/**
 * @brief Copy-constructs a MutantStack.
 * @param other - Source stack to copy.
 */
template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack& other)
	: std::stack<T, Container>(other) {}

/**
 * @brief Destroys the MutantStack instance.
 */
template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack(void) {}

/**
 * @brief Assigns content from another MutantStack.
 * @param other - Source stack.
 * @return Reference to this stack.
 */
template <typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack& other)
{
	if (this != &other)
		std::stack<T, Container>::operator=(other);
	return (*this);
}

/**
 * @brief Returns iterator to the first element.
 * @return Iterator to beginning.
 */
template <typename T, typename Container>
typename MutantStack<T, Container>::iterator
MutantStack<T, Container>::begin(void)
{
	return (this->c.begin());
}

/**
 * @brief Returns iterator past the last element.
 * @return Iterator to end.
 */
template <typename T, typename Container>
typename MutantStack<T, Container>::iterator
MutantStack<T, Container>::end(void)
{
	return (this->c.end());
}

/**
 * @brief Returns const iterator to the first element.
 * @return Const iterator to beginning.
 */
template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator
MutantStack<T, Container>::begin(void) const
{
	return (this->c.begin());
}

/**
 * @brief Returns const iterator past the last element.
 * @return Const iterator to end.
 */
template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator
MutantStack<T, Container>::end(void) const
{
	return (this->c.end());
}

/**
 * @brief Returns reverse iterator to the first reverse element.
 * @return Reverse iterator to reverse beginning.
 */
template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator
MutantStack<T, Container>::rbegin(void)
{
	return (this->c.rbegin());
}

/**
 * @brief Returns reverse iterator past the last reverse element.
 * @return Reverse iterator to reverse end.
 */
template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator
MutantStack<T, Container>::rend(void)
{
	return (this->c.rend());
}

/**
 * @brief Returns const reverse iterator to reverse beginning.
 * @return Const reverse iterator to reverse beginning.
 */
template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator
MutantStack<T, Container>::rbegin(void) const
{
	return (this->c.rbegin());
}

/**
 * @brief Returns const reverse iterator to reverse end.
 * @return Const reverse iterator to reverse end.
 */
template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator
MutantStack<T, Container>::rend(void) const
{
	return (this->c.rend());
}