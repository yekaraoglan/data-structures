#pragma once

#include <iostream>

class Stack {
    private:
        int top;
        int *stack;
        int size;

    public:
        Stack(int);
        ~Stack();
        void push(int);
        int pop();
        void print();
        bool isEmpty();
        bool isFull();

};