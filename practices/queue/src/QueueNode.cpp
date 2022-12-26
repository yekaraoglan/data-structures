#include "QueueNode.h"

QueueNode::QueueNode(int data){
    this->data = data;
    this->next = nullptr;
}

QueueNode::~QueueNode(){
    this->next = nullptr;
}

int QueueNode::get_data(){
    return this->data;
}

void QueueNode::set_data(int data){
    this->data = data;
}

QueueNode* QueueNode::get_next(){
    return this->next;
}

void QueueNode::set_next(QueueNode* next){
    this->next = next;
}