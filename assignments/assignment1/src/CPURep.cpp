/* @Author
Student Name: Yunus Emre Karaoglan
Student ID : 150220732
Date: 21-10-2022
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
// #include "node.h"
#include "ProcessRep.h"
#include "FIFORep.h"
#include "CPURep.h"

using namespace std;

CPURep::CPURep()
{
    // Constructor for the CPURep class, a FIFORep linked list is initialized to store the finished process info.
    this->mFinishedProcess = new FIFORep();
}

CPURep::~CPURep()
{
    /*
        Destructor for the CPURep class, delete the initialized FIFORep not to have any memory leak.
    */
    delete this->mFinishedProcess;
}

ProcessRep* CPURep::runCPU(ProcessRep* p, int time)
{   
    /*
        Run one step of CPU running process.
    */
    // If process is NULL, return NULL
    if (p == NULL)
        return NULL;
    // If process is not NULL:
    // if process is run by CPU for the first time, set start time to totalTime
    // decrease remainingTime and processTime to execute the process.
    else{
        if (p->startTime == -1)
            p->startTime = time;
        p->remainingTime--;
        p->setProcessTime(p->getProcessTime()-1);
        return p;
    }
}

FIFORep* CPURep::getFinishedProcess()
{
    // get the FIFO linked list for finished processes 
    return this->mFinishedProcess;
}

void CPURep::setFinishedProcess(FIFORep* finishedProcess)
{
    // set the FIFO linked list for finished processes 
    this->mFinishedProcess = finishedProcess;
}