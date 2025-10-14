#include "stack.h"
#include <iostream>
#include <stdexcept>
using namespace std;


Stack::Stack() {
    length = 0;
    structure = new ItemType[MAX_ITEMS];
}

Stack::~Stack() {
    delete[] structure;
}

bool Stack::isEmpty() const {
    return length == 0;
}

bool Stack::isFull() const {
    return length == MAX_ITEMS;
}

void Stack::push(ItemType item) {
    if (!isFull()) {
        structure[length] = item;
        length++;
    }
    else {
        throw overflow_error("Stack is full");
    }
}

ItemType Stack::pop() {
    if (!isEmpty()) {
        ItemType aux = structure[length - 1];
        length--;
        return aux;
    }
    else {
        throw underflow_error("Stack is empty");
    }
}

void Stack::print() const {
    for (int i = length - 1; i >= 0; i--) {
        cout << structure[i] << " ";
    }
    cout << endl;
}
