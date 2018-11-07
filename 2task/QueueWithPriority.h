#ifndef QUEUEWITHPRIORITY_H
#define QUEUEWITHPRIORITY_H

#include<string>
#include<list>
#include<memory>
#include<iostream>
#include<ostream>
#include<iterator>

template < typename T >
class QueueWithPriority
{
public:
	enum ElementPriority { LOW, NORMAL, HIGH };
private:
	struct Element
	{
		T value;
		//ElementPriority priority;
		Element(T _value):
			value(_value)
			//priority = (_priority)
		{}
		friend std::ostream & operator << (std::ostream & stream, Element & element)
		{
			return stream << element.value << std::endl;
		}

	};
	std::list<Element> lowPriority, normalPriority, highPriority;
public:
	void Put(const T & value, ElementPriority priority)
	{
		switch(priority)
		{
			case LOW:
			{
				lowPriority.push_back(Element(value));
				break;
			} 
			case NORMAL:
			{
				normalPriority.push_back(Element(value));
				break;

			}
			case HIGH:
			{
				highPriority.push_back(Element(value));
				break;
			}
		}
	}
	std::shared_ptr< T > Get()
	{
		if (lowPriority.empty() && normalPriority.empty() && highPriority.empty())
		{
			std::cerr << "Empty queue\n";
			std::shared_ptr< T > ptrToReturn;
			return ptrToReturn;
		}
		else if (!highPriority.empty())
		{
			std::shared_ptr< T > ptrToReturn(new T((highPriority.front()).value));
			highPriority.pop_front();
			return ptrToReturn;
		}
		else if (!normalPriority.empty())
		{
			std::shared_ptr< T > ptrToReturn(new T((normalPriority.front()).value));
			normalPriority.pop_front();
			return ptrToReturn;
		}
		else if (!lowPriority.empty())
		{
			std::shared_ptr< T > ptrToReturn(new T((lowPriority.front()).value));
			lowPriority.pop_front();
			return ptrToReturn;
		}
	}

	void Accelerate()
	{
		while (!lowPriority.empty())
		{
			highPriority.splice(highPriority.begin(), lowPriority);
		}
	}
	void Print()
	{
		std::cout << "LOW\n";
		for (std::list<Element>::iterator it = lowPriority.begin(); it != lowPriority.end(); ++it)
		{
			std::cout << *it;
		}
		std::cout << "NORMAL\n";
		for (std::list<Element>::iterator it = normalPriority.begin(); it != normalPriority.end(); ++it)
		{
			std::cout << *it;
		}
		std::cout << "HIGH\n";
		for (std::list<Element>::iterator it = highPriority.begin(); it != highPriority.end(); ++it)
		{
			std::cout << *it;
		}
	}
	size_t Size()
	{
		return highPriority.size() + normalPriority.size() + lowPriority.size();
	}
};


#endif