#ifndef HEADER_H
#define HEADER_H

template < typename T>
class PolicySortWithIndex
{
public:
	typedef typename T::size_type position_type;
	typedef typename T::value_type value_type;

	static position_type begin(T & container)
	{
		return 0;
	}
	static position_type end(T & container)
	{
		return container.size();
	}
	static value_type& get(T & container, position_type i)
	{
		return container[i];
	}
};
template < typename T>
class PolicySortWithAt
{
public:
	typedef typename T::size_type position_type;
	typedef typename T::value_type value_type;

	static position_type begin(T & container)
	{
		return 0;
	}
	static position_type end(T & container)
	{
		return container.size();
	}
	static value_type& get(T & container, position_type i)
	{
		return container.at(i);
	}
}; template < typename T>
class PolicySortWithIterator
{
public:
	typedef typename T::iterator position_type;
	typedef typename T::value_type value_type;

	static position_type begin(T & container)
	{
		return container.begin();
	}
	static position_type end(T & container)
	{
		return container.end();
	}
	static value_type& get(T & container, position_type i)
	{
		return *i;
	}
};
template <template <typename T> class Policy, typename T>
void sort(T & container) 
{
	typedef Policy<T> curPolicy;
	typedef typename curPolicy::position_type position_type;

	for (position_type i = curPolicy::begin(container); i != curPolicy::end(container); ++i)
		for (position_type j = i; (j > curPolicy::begin(container)) && (curPolicy::get(container, j) < curPolicy::get(container, j - 1)); --j)
			std::swap(curPolicy::get(container, j), curPolicy::get(container, j - 1));

}

#endif