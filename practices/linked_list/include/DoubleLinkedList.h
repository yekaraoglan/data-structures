#pragma once

#include "DoubleNode.h"

class DoubleLinkedList{
    private:
        DoubleLinkedListNode* head;
        DoubleLinkedListNode* tail;
    public:
        DoubleLinkedList();
        ~DoubleLinkedList();
        void add_to_head(int);
        void add_to_tail(int);
        void remove_from_head();
        void remove_from_tail();
        void print();
        void reverse();

};