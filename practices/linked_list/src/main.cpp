#include "SingleLinkedList.h"
#include "SingleNode.h"
#include <iostream>

int main(){
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

    return 0;
}