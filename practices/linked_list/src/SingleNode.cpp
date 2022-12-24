#include "SingleNode.h"

SingleLinkedListNode::SingleLinkedListNode(int data) {
    this->data = data;
    next = nullptr;
}

int SingleLinkedListNode::getData() {
    return data;
}

SingleLinkedListNode* SingleLinkedListNode::getNext() {
    return next;
}

void SingleLinkedListNode::setData(int data) {
    this->data = data;
}

void SingleLinkedListNode::setNext(SingleLinkedListNode* next) {
    this->next = next;
}