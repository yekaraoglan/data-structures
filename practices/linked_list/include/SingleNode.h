#pragma once

#include <iostream>
#include <string>

class SingleLinkedListNode{
    private:
        int data;
        SingleLinkedListNode* next;
    public:
        SingleLinkedListNode(int data);
        int getData();
        SingleLinkedListNode* getNext();
        void setData(int data);
        void setNext(SingleLinkedListNode* next);
};