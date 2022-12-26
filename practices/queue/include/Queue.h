#pragma once 

#include "QueueNode.h"

class Queue{
    private:
        QueueNode* front;
        QueueNode* rear;
    public:
        Queue();
        ~Queue();
        void enqueue(int data);
        int dequeue();
        bool is_empty();
        void print();
        int get_front();
        int get_rear();
};