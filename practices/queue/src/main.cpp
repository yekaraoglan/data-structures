#include "Queue.h"

int main(){
    Queue* queue = new Queue();
    queue->enqueue(1);
    queue->enqueue(2);
    queue->enqueue(3);
    queue->enqueue(4);
    queue->enqueue(5);
    queue->print();
    std::cout << "Front: " << queue->get_front() << std::endl;
    std::cout << "Rear: " << queue->get_rear() << std::endl;
    std::cout << "Dequeue: " << queue->dequeue() << std::endl;
    std::cout << "Dequeue: " << queue->dequeue() << std::endl;
    std::cout << "Dequeue: " << queue->dequeue() << std::endl;
    queue->print();
    std::cout << "Front: " << queue->get_front() << std::endl;
    std::cout << "Rear: " << queue->get_rear() << std::endl;
    delete queue;
    return 0;
}