#include <iostream>
#include "vector.h"

using namespace std;
int main() {
	Vector<int> vec{1,2,3,4,5,6,7,8};
	Vector<Vector<int>> vec2;
	
	for (auto x : vec2)
		for (auto m : x)
			cout << m << endl;
	
	system("pause");
	return 0;
}