#pragma once

#include <iostream>

class DoubleLinkedListNode{
    private:
        int data;
        DoubleLinkedListNode* next;
        DoubleLinkedListNode* prev;
    public:
        DoubleLinkedListNode(int);
        ~DoubleLinkedListNode();
        void set_data(int);
        int get_data();
        void set_next(DoubleLinkedListNode*);
        DoubleLinkedListNode* get_next();
        void set_prev(DoubleLinkedListNode*);
        DoubleLinkedListNode* get_prev();
};