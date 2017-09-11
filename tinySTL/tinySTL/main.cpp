#include <iostream>
#include "vector.h"
#include "String.h"
using namespace std;
std::allocator<char> String::a;
int main() {
	Vector<int> vec{1,2,3,4,5,6,7,8};
	Vector<Vector<int>> vec2;
	cout << "Êä³öÎÒµÄvector" << endl;
	for (auto x : vec)
		cout << x << endl;
	system("pause");
	return 0;
}