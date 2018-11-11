#include<vector>
#include<string>
#include"DataVector.h"

int main()
{
	DataVector vector(5);
	vector.print();
	vector.sort();
	vector.print();
	
	return 0;
}