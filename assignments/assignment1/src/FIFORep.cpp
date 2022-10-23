/* @Author
Student Name: Yunus Emre Karaoglan
Student ID : 150220732
Date: 20-10-2022
*/
#include <iostream> 
#include <stdio.h>
#include <string.h>

#include "ProcessRep.h"
#include "FIFORep.h"

using namespace std;

FIFORep::FIFORep()
{
    // Non-parameter Constructor of the FIFO Linked List data structure. Head and tail are not set, so they are set to NULL
    this->mpHead = NULL;
    this->mpTail = NULL;
}

FIFORep::FIFORep(ProcessRep* head)
{
    // Constructor with parameter of the FIFO Linked List data structure. Head and tail are set to given pointer
    this->mpHead = head;
    this->mpTail = this->mpHead;
}


FIFORep::~FIFORep()
{
    // Destructor of the FIFO Linked List data structure.
    // Traverse the linked list and delete all elements
    ProcessRep* tmp = this->mpHead;
    ProcessRep* ptr;
    while(tmp != NULL){
        ptr = tmp;
        tmp = tmp->getNext();
        delete ptr;
    }
}

void FIFORep::setHead(ProcessRep* head)
{
    // set head pointer of the FIFO linked list
    this->mpHead = head;
}

ProcessRep* FIFORep::getHead()
{
    // get head pointer of the FIFO linked list
    return this->mpHead;
}

void FIFORep::setTail(ProcessRep* tail)
{
    // set tail pointer of the FIFO linked list
    this->mpTail = tail;
}

ProcessRep* FIFORep::getTail()
{
    // get tail pointer of the FIFO linked list
    return this->mpTail;
}

void FIFORep::queue(ProcessRep* p)
{
    /*
        The function add a process to the tail of the queue.
    */

    // If head (and also tail) is(are) NULL, set p as head and tail of the linked list
    if (this->mpHead == NULL){
        this->mpHead = p;
        this->mpTail = this->mpHead;
        return;
    }
    // If linked list is not empty, add p at the tail of the linked list
    this->mpTail->setNext(p);
    this->mpTail = p;
}

ProcessRep* FIFORep::dequeue()
{   
    /*
        The function removes a process from the HEAD of the FIFO and returns it. If there is no item, it returns NULL
    */   
    // If linked list is empty, return NULL pointer
    if (this->mpHead == NULL)
        return NULL;
    // temp pointer equals to head of the linked list to remember the head since we have no prev pointer in the list 
    ProcessRep* temp = this->mpHead;
    
    // If linked list has only one element, set head and tail to NULL pointers
    if (this->mpTail == this->mpHead){
        this->mpHead = this->mpHead->getNext();
        this->mpTail = this->mpHead;
    }
    else{
    // If linked list has more than one elements, set head to next element of head, and set dequeued element's next to NULL
        this->mpHead = this->mpHead->getNext();
    }
    temp->setNext(NULL);
    return temp;
}

ProcessRep* FIFORep::searchID(int id)
{   
    /*
        The function search a process by id and returns it if it exist otherwise returns NULL.
    */ 
    // If linked list has no element in it, return NULL
    if(this->mpHead == NULL)
        return NULL;
    // temp pointer is set to head, and used in searching by setting its next at each step
    ProcessRep* temp = this->mpHead;
    while(temp->getNext() != NULL && temp->getProcessID() != id)
        temp = temp->getNext();
    // searching progress may be terminated because of id was found or finished the linked list, so we should check if it is found
    if (temp->getProcessID() == id)
        return temp;
    return NULL;
}

void FIFORep::printFIFO()
{
    /*
        The function prints the proceses in the queue starting from Head to tail.
    */
    // Check if linked list is empty or not
    if (this->mpHead == NULL)
        return;
    // Traverse the linked list by temp pointer, print time info. 
    ProcessRep* temp = this->mpHead;
    while(temp != NULL){
        std::cout   << temp->getProcessType() 
                    << temp->getProcessID()
                    << " " << temp->startTime
                    << " " << temp->endTime
                    << " ";
        temp = temp->getNext();
    }
}