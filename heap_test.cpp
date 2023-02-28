#include "heap.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{


	cout << "hi" << endl;

	Heap<int> h1;
	
	h1.push(2);
	h1.push(3);
	h1.push(1);

	cout << h1.top() << endl;

	h1.pop();

	cout << h1.top() << endl;

	h1.pop();

	cout << h1.top() << endl;


	h1.pop();



	return 0;
}