#ifndef EASYFIND_TPP
# define EASYFIND_TPP

inline const char* NotFoundException::what() const throw()
{
	return "easyfind: value not found";
}

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw NotFoundException();
	return it;
}

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