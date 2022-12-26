#pragma once 

#include <iostream>

class QueueNode{
    private:
        int data;
        QueueNode* next;
    public:
        QueueNode(int data);
        ~QueueNode();
        int get_data();
        void set_data(int data);
        QueueNode* get_next();
        void set_next(QueueNode* next);
};