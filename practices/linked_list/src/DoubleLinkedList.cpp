#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList(){
    this->head = nullptr;
    this->tail = nullptr;
}

DoubleLinkedList::~DoubleLinkedList(){
    DoubleLinkedListNode* temp = this->head;
    while(temp != nullptr){
        this->head = this->head->get_next();
        delete temp;
        temp = this->head;
    }
}

void DoubleLinkedList::add_to_head(int data){
    DoubleLinkedListNode* new_node = new DoubleLinkedListNode(data);
    if(this->head == nullptr){
        this->head = new_node;
        this->tail = new_node;
    }else{
        new_node->set_next(this->head);
        this->head->set_prev(new_node);
        this->head = new_node;
    }
}

void DoubleLinkedList::add_to_tail(int data){
    DoubleLinkedListNode* new_node = new DoubleLinkedListNode(data);
    if(this->tail == nullptr){
        this->head = new_node;
        this->tail = new_node;
    }else{
        new_node->set_prev(this->tail);
        this->tail->set_next(new_node);
        this->tail = new_node;
    }
}

void DoubleLinkedList::remove_from_head(){
    if(this->head == nullptr){
        return;
    }else if(this->head == this->tail){
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
    }else{
        DoubleLinkedListNode* temp = this->head;
        this->head = this->head->get_next();
        this->head->set_prev(nullptr);
        delete temp;
    }
}

void DoubleLinkedList::remove_from_tail(){
    if(this->tail == nullptr){
        return;
    }else if(this->head == this->tail){
        delete this->tail;
        this->head = nullptr;
        this->tail = nullptr;
    }else{
        DoubleLinkedListNode* temp = this->tail;
        this->tail = this->tail->get_prev();
        this->tail->set_next(nullptr);
        delete temp;
    }
}

void DoubleLinkedList::print(){
    DoubleLinkedListNode* temp = this->head;
    while(temp != nullptr){
        std::cout << temp->get_data() << " ";
        temp = temp->get_next();
    }
    std::cout << std::endl;
}

void DoubleLinkedList::reverse(){
    DoubleLinkedListNode* temp = this->head;
    this->head = this->tail;
    this->tail = temp;
    while(temp != nullptr){
        DoubleLinkedListNode* next = temp->get_next();
        temp->set_next(temp->get_prev());
        temp->set_prev(next);
        temp = next;
    }
}