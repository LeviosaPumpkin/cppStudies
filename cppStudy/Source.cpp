#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

#include"header.h"

void readFromFileToVector(const std::string path, std::string & str);
void vectorProcess();

int main()
{
	int check[] = { 2, 3, 5, 5, 6 };
	std::vector<int> vector = {2, 5, 3, 5, 6};
	sort<PolicySortWithIndex>(vector);
	if (std::equal(vector.begin(), vector.end(), check)) std::cout << "Sort [] is correct\n";
	vector = { 2, 5, 3, 5, 6 };
	sort<PolicySortWithAt>(vector);
	if (std::equal(vector.begin(), vector.end(), check)) std::cout << "Sort .at() is correct\n";
	vector = { 2, 5, 3, 5, 6 };
	sort<PolicySortWithIterator>(vector);
	if (std::equal(vector.begin(), vector.end(), check)) std::cout << "Sort iterator is correct\n";

	std::string str = "";
	std::string path = "file.txt";
	readFromFileToVector(path, str);
	std::cout << str << "\n";

	vectorProcess();

	return 0;
}