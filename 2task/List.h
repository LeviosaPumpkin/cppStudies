#ifndef LIST_H
#define LIST_H

#include<list>
#include<iostream>
#include<iterator>
#include<ctime>
#include<algorithm>

template < typename T >
class List
{
private:
	std::list<T> list;
public:
	List(size_t size)
	{
		for (int i = 0; i < size; ++i) list.push_back(1 + std::rand() % 20);
	}
	void printInOrder()
	{
		for (std::list<T>::iterator it = list.begin(); it != list.end(); ++it) std::cout << *it << " ";
		std::cout << "\n";
	}
	void printFirstLastOrder()
	{
		std::list<T>::iterator begin = list.begin();
		std::list<T>::iterator end = --list.end();
		if (begin == end) std::cout << *begin;
		else if (list.size() % 2 != 0)
		{
			while (begin != end)
			{
				std::cout << *begin << " " << *end<<" ";
				++begin;
				--end;
			}
			std::cout << *begin;
		}
		else if (list.size() % 2 == 0)
		{
			while (begin != (++end)--)
			{
				std::cout << *begin << " " << *end<<" ";
				++begin;
				--end;
			}
		}
		std::cout << "\n";
	}
};

#endif
