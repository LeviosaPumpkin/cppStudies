#include <vector>
#include <iostream>
#include <algorithm>

void vectorProcess()
{
	std::vector<int> v;
	int n = 1;
	std::cin >> n;
	while (n != 0)
	{
		v.push_back(n);
		std::cin >> n;
	}
	if (*(v.end()-1) == 1) v.erase(std::remove_if(v.begin(), v.end(), [](int n) {return n % 2 == 0; }));
	std::for_each(v.begin(), v.end(), [](int n) {std::cout << n << " "; });

}