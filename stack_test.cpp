#include "stack.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{

	Stack<char> stack;

	stack.push('b');

	stack.push('a');

	cout << stack.size() << endl;
	cout << stack.top() << endl;

	stack.pop();

	cout << stack.top() << endl;

	cout << stack.empty() << endl;

	stack.pop();

	cout << stack.empty() << endl;
	

	return 0;
}