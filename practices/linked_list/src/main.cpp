#include "SingleNode.h"
#include "SingleLinkedList.h"

#include "DoubleNode.h"
#include "DoubleLinkedList.h"

#include <iostream>

void single_ll_example(){
    SingleLinkedList* list = new SingleLinkedList();
    list->add_to_head(1);
    list->add_to_head(2);
    list->add_to_head(3);

    list->add_to_tail(4);
    list->add_to_tail(5);

    list->remove_from_head();
    list->remove_from_tail();

    list->print();
    list->reverse();
    list->print();

    delete list;
}

void double_ll_example(){
    DoubleLinkedList* list = new DoubleLinkedList();
    list->add_to_head(1);
    list->add_to_head(2);
    list->add_to_head(3);

    list->add_to_tail(4);
    list->add_to_tail(5);

    list->remove_from_head();
    list->remove_from_tail();

    list->print();
    list->reverse();
    list->print();

    delete list;
}

int main(){
    // single_ll_example();
    double_ll_example();
    return 0;
}
