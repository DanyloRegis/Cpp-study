#include <iostream>
#include "stack.h"
#include "item_type.h"
#include "stack.cpp"
using namespace std;

int main() {
	ItemType character;
	Stack stack;
	ItemType stackItem;

	cout << "Enter a string: ";
	cin.get(character);
	while (character != '\n')
	{
		stack.push(character);
		cin.get(character);
	}

	while (!stack.isEmpty())
	{
		stackItem = stack.pop();
		cout << stackItem;
	}
	cout << endl;

    Stack stack01;
    stack01.print();
    stack01.push('A');
    stack01.print();
    stack01.push('B');
    stack01.print();

    return 0;
}