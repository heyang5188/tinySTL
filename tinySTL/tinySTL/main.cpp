#include <iostream>
#include "vector.h"
#include "List.h"
#include "String.h"
using namespace std;
std::allocator<char> String::a;
int main() {

	herb::list<int> lis;
	lis.push_back(4);
	lis.push_back(6);
	lis.push_back(6);
	lis.push_back(6);
	lis.push_back(6);
	lis.push_back(6);
	lis.pop_front();
	auto it = lis.begin();
	for (it; it != lis.end(); it++)
	{
		cout << *it << endl;
	}
	cout << "Êä³öÎÒµÄvector" << endl;

	system("pause");
	return 0;
}