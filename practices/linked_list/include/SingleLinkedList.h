#pragma once

#include "SingleNode.h"
#include <iostream>
#include <string>

class SingleLinkedList{
    private:
        SingleLinkedListNode* head;
        SingleLinkedListNode* tail;
    public:
        SingleLinkedList();
        ~SingleLinkedList();
        SingleLinkedListNode* getHead();
        SingleLinkedListNode* getTail();
        void setHead(SingleLinkedListNode* head);
        void setTail(SingleLinkedListNode* tail);

        void add_to_head(int data);
        void add_to_tail(int data);
        void remove_from_head();
        void remove_from_tail();
        void print();
        void reverse();
};
