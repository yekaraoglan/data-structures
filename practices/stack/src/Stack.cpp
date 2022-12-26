#include "Stack.h"

Stack::Stack(int size) {
    top = -1;
    this->size = size;
    stack = new int[this->size];
}

Stack::~Stack() {
    delete[] stack;
}

void Stack::push(int value) {
    if (isFull()) {
        std::cout << "Stack is full" << std::endl;
    } else {
        top++;
        stack[top] = value;
    }
}

int Stack::pop() {
    if (isEmpty()) {
        std::cout << "Stack is empty" << std::endl;
        return -1;
    } else {
        int value = stack[top];
        top--;
        return value;
    }
}

void Stack::print() {
    if (isEmpty()) {
        std::cout << "Stack is empty" << std::endl;
    } else {
        for (int i = top; i >= 0; i--) {
            std::cout << stack[i] << std::endl;
        }
    }
}

bool Stack::isEmpty() {
    return top == -1;
}

bool Stack::isFull() {
    return top == size - 1;
}