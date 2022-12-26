#include "DoubleNode.h"

DoubleLinkedListNode::DoubleLinkedListNode(int data){
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
}

DoubleLinkedListNode::~DoubleLinkedListNode(){
}

int DoubleLinkedListNode::get_data(){
    return this->data;
}

void DoubleLinkedListNode::set_data(int data){
    this->data = data;
}

DoubleLinkedListNode* DoubleLinkedListNode::get_next(){
    return this->next;
}

void DoubleLinkedListNode::set_next(DoubleLinkedListNode* next){
    this->next = next;
}

DoubleLinkedListNode* DoubleLinkedListNode::get_prev(){
    return this->prev;
}

void DoubleLinkedListNode::set_prev(DoubleLinkedListNode* prev){
    this->prev = prev;
}