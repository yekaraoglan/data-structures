/* @Author
Student Name: Yunus Emre Karaoglan
Student ID : 150220732
Date: 20-10-2022
*/
#include <iostream> 
#include <stdio.h>
#include <string>
#include "ProcessRep.h"


using namespace std;

ProcessRep::ProcessRep(string processType, int processID, int deliverTime, int processTime)
{   
    /*
        Constructor of the ProcessRep class.
    */

    // Assign parameter values to private attributes.
    this->mpNext = NULL;
    this->mProcessType = processType;
    this->mProcessID = processID;
    this->mDeliverTime = deliverTime;
    this->mProcessTime = processTime;

    // Assign CPU usage limits with respect to type of processes.
    if (mProcessType == "A")
        remainingTime = 2;
    else if (mProcessType == "B")
        remainingTime = 4;
    else
        remainingTime = 8;

    // Start time and end time of a process equals to -1 at first.
    this->startTime = -1;
    this->endTime = -1;
}

ProcessRep::~ProcessRep()
{
    // delete the next pointer
    delete this->mpNext;
}

ProcessRep* ProcessRep::getNext()
{
    // get next pointer
    return this->mpNext;
}

void ProcessRep::setNext(ProcessRep *next)
{
    // set next pointer to a pointer as parameter
    this->mpNext = next;
}

string ProcessRep::getProcessType()
{
    // get process type
    return this->mProcessType;
}

void ProcessRep::setProcessType(string processType)
{
    // set process type
    this->mProcessType = processType;
}

int ProcessRep::getDeliverTime()
{
    // get arrival time of the process
    return this->mDeliverTime;
}

void ProcessRep::setDeliverTime(int deliverTime)
{
    // set arrival time of the process
    this->mDeliverTime = deliverTime;
}

int ProcessRep::getProcessID()
{
    // get ID of the process
    return this->mProcessID;
}

void ProcessRep::setProcessID(int processID)
{
    // set ID of the process
    this->mProcessID = processID;
}

int ProcessRep::getProcessTime()
{
    // get remaining CPU Usage time of the process
    return this->mProcessTime;
}

void ProcessRep::setProcessTime(int ProcessTime)
{
    // set remaining CPU Usage time of the process
    this->mProcessTime = ProcessTime;
}