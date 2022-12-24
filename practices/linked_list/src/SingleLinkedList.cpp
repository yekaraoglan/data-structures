#include "SingleLinkedList.h"

SingleLinkedList::SingleLinkedList() {
    head = nullptr;
    tail = nullptr;
}

SingleLinkedList::~SingleLinkedList() {
    SingleLinkedListNode* node = head;
    SingleLinkedListNode* next = nullptr;
    while (node != nullptr) {
        next = node->getNext();
        delete node;
        node = next;
    }
}

SingleLinkedListNode* SingleLinkedList::getHead() {
    return head;
}

SingleLinkedListNode* SingleLinkedList::getTail() {
    return tail;
}

void SingleLinkedList::setHead(SingleLinkedListNode* head) {
    this->head = head;
}

void SingleLinkedList::setTail(SingleLinkedListNode* tail) {
    this->tail = tail;
}

void SingleLinkedList::add_to_head(int data) {
    SingleLinkedListNode* node = new SingleLinkedListNode(data);
    if (head == nullptr) {
        head = node;
        tail = node;
    } else {
        node->setNext(head);
        head = node;
    }
}

void SingleLinkedList::add_to_tail(int data) {
    SingleLinkedListNode* node = new SingleLinkedListNode(data);
    if (tail == nullptr) {
        head = node;
        tail = node;
    } else {
        tail->setNext(node);
        tail = node;
    }
}

void SingleLinkedList::remove_from_head() {
    if (head == nullptr) {
        return;
    } else {
        SingleLinkedListNode* node = head;
        head = head->getNext();
        delete node;
    }
}

void SingleLinkedList::remove_from_tail() {
    if (tail == nullptr) {
        return;
    } else {
        SingleLinkedListNode* node = head;
        while (node->getNext() != tail) {
            node = node->getNext();
        }
        delete tail;
        tail = node;
        tail->setNext(nullptr);
    }
}

void SingleLinkedList::print() {
    SingleLinkedListNode* node = head;
    while (node != nullptr) {
        std::cout << node->getData() << std::endl;
        node = node->getNext();
    }
}

void SingleLinkedList::reverse() {
    SingleLinkedListNode* node = head;
    SingleLinkedListNode* prev = nullptr;
    SingleLinkedListNode* next = nullptr;
    while (node != nullptr) {
        next = node->getNext();
        node->setNext(prev);
        prev = node;
        node = next;
    }
    head = prev;
}

