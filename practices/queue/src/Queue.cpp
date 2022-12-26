#include "Queue.h"

Queue::Queue(){
    this->front = nullptr;
    this->rear = nullptr;
}

Queue::~Queue(){
    this->front = nullptr;
    this->rear = nullptr;
}

bool Queue::is_empty(){
    return this->front == nullptr;
}

void Queue::enqueue(int data){
    QueueNode* new_node = new QueueNode(data);
    if(this->is_empty()){
        this->front = new_node;
        this->rear = new_node;
    }else{
        this->rear->set_next(new_node);
        this->rear = new_node;
    }
}

int Queue::dequeue(){
    if(this->is_empty()){
        return -1;
    }else{
        QueueNode* temp = this->front;
        this->front = this->front->get_next();
        int data = temp->get_data();
        delete temp;
        return data;
    }
}

void Queue::print(){
    QueueNode* temp = this->front;
    while(temp != nullptr){
        std::cout << temp->get_data() << " ";
        temp = temp->get_next();
    }
    std::cout << std::endl;
}

int Queue::get_front(){
    if(this->is_empty()){
        return -1;
    }else{
        return this->front->get_data();
    }
}

int Queue::get_rear(){
    if(this->is_empty()){
        return -1;
    }else{
        return this->rear->get_data();
    }
}

