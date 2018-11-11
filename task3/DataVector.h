#ifndef DATAVECTOR_H
#define DATAVECTOR_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

const std::vector<std::string> TABLE = { "When", "you", "travel", "by", "sea", "you", "can", "see", "awesome", "sunsets" };

class DataVector
{
private:
	struct DataStruct
	{
		int key1, key2;
		std::string str;
		DataStruct(){}
		DataStruct(int _key1, int _key2, std::string _str):
			key1(_key1), key2(_key2), str(_str)
		{}
		friend std::ostream & operator << (std::ostream & stream, const DataStruct & element)
		{
			return stream << element.key1 << " " << element.key2 << " " << element.str << std::endl;
		}
	};
	struct Comparator
	{
		bool operator () (const DataStruct &lhs, const DataStruct &rhs) const
		{
			return ((lhs.key1 < rhs.key1)
				|| (lhs.key1 == rhs.key1) && (lhs.key2 < rhs.key2)
				|| (lhs.key1 == rhs.key1) && (lhs.key2 == rhs.key2) && (lhs.str.length() < rhs.str.length()));
		}
	};
	std::vector<DataStruct> vector;
public:
	DataVector(int n)
	{
		vector.resize(n);
		std::generate(vector.begin(), vector.end(), [](){return DataStruct(std::rand() % 10 - 5, std::rand() % 10 - 5, TABLE.at(std::rand() % 10)); });

	}
	void print()
	{
		std::copy(vector.begin(), vector.end(), std::ostream_iterator<DataStruct>(std::cout));
	}
	void sort()
	{
		std::sort(vector.begin(), vector.end(), Comparator());
	}
};


#endif
