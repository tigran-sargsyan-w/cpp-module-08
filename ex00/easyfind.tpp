#ifndef EASYFIND_TPP
# define EASYFIND_TPP

/**
 * @brief Returns the error message for missing value.
 * @return Static exception message.
 */
inline const char* NotFoundException::what() const throw()
{
	return "easyfind: value not found";
}

/**
 * @brief Finds a value in a mutable container.
 * @tparam T Container type.
 * @param container - Container to search in.
 * @param value - Value to locate.
 * @return Iterator to the found element.
 */
template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw NotFoundException();
	return it;
}

/**
 * @brief Finds a value in a const container.
 * @tparam T Container type.
 * @param container - Const container to search in.
 * @param value - Value to locate.
 * @return Const iterator to the found element.
 */
template <typename T>
typename T::const_iterator easyfind(const T& container, int value)
{
	typename T::const_iterator it;

	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw NotFoundException();
	return it;
}

#endif