#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

void readFromFileToVector(const std::string path, std::string & str)
{
	std::ifstream file(path);
	std::copy(std::istream_iterator<char>(file), std::istream_iterator<char>(), std::back_inserter(str));
}