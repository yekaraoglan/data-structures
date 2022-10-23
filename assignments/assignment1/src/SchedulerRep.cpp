/* @Author
Student Name: Yunus Emre Karaoglan
Student ID : 150220732
Date: 22-10-2022
*/
#include <iostream> 
#include <stdio.h>
#include <string.h>
#include "SchedulerRep.h"

using namespace std;

SchedulerRep::SchedulerRep()
{
    // Constructor for the Scheduler, initialize the FIFO linked lists of the scheduler. 
    // Running process is NULL since there is no process in the beginning.
    // A new CPU object is initialized for the scheduler.
    *(this->mpProcessFIFO) = new FIFORep();
    *(this->mpProcessFIFO +1) = new FIFORep();
    *(this->mpProcessFIFO +2) = new FIFORep();
    this->mpRunningProcess = NULL;
    this->pCpuObj = new CPURep();
}
SchedulerRep::~SchedulerRep()
{
    // Destructor for the SchedulerRep class
    // delete initialized FIFO linked lists, running process and CPU object.
    delete *(this->mpProcessFIFO+2);
    delete *(this->mpProcessFIFO+1);
    delete *(this->mpProcessFIFO);
    delete this->mpRunningProcess;
    delete this->pCpuObj;
}

FIFORep* SchedulerRep::getProcessFIFO(int index)
{
    // get the FIFO linked list for the specific index. If index is not in [0, 2], return NULL.  
    if (index > -1 && index < 3)
        return this->mpProcessFIFO[index];
    return NULL;
}

void SchedulerRep::setProcessFIFO(FIFORep* fifo, int index)
{
    // set FIFO linked list for the specific index.
    this->mpProcessFIFO[index] = fifo;
}

void SchedulerRep::setRunningProcess(ProcessRep* p)
{
    // set the running process for the scheduler.
    this->mpRunningProcess = p;
}

ProcessRep* SchedulerRep::getRunningProcess()
{
    // get the running process for the scheduler.
    return this->mpRunningProcess;
}

void SchedulerRep::pushProcess(ProcessRep* p)
{
    // push a process in the FIFO linked lists:
    // First, check ProcessType of the process.
    // Second, queue the process to an appropriate linked list
    // Finally, set remaining time with respect to process type,
    // Since it may be zero when process reached its limit while being executed CPU.
    if(p->getProcessType() == "A"){
        mpProcessFIFO[0]->queue(p);
        p->remainingTime = 2;
    }
    else if(p->getProcessType() == "B"){
        mpProcessFIFO[1]->queue(p);
        p->remainingTime = 4;
    }
    else if(p->getProcessType() == "C"){
        mpProcessFIFO[2]->queue(p);
        p->remainingTime = 8;
    }
}

ProcessRep* SchedulerRep::popProcess()
{
    // pop a process from the FIFO linked lists:
    // Traverse the linked lists as: A -> B -> C
    // If there is not any process in the FIFO linked lists, return NULL.
    ProcessRep* p;
    for (int i = 0; i < 3; i++){
        p = mpProcessFIFO[i]->dequeue();
        if (p != NULL){
            return p;
        }
    }
    return NULL;
}

bool SchedulerRep::checkTimeSlice()
{   
    // Check if running process reaches the time limit of the CPU execution
    // Each process type its own specific time limit ([l] -> 2^l)
    // return true if time limit is reached, otherwise return false.
    if (timeSliceCount == mpRunningProcess->remainingTime)
        return true;
    return false;
}

ProcessRep* SchedulerRep::sendProcessToCPU(ProcessRep* p){
    // Send a process to cpu basically set it as running process, and return it.
    this->setRunningProcess(p);
    return p;
}

void SchedulerRep::schedule(string type, int id, int arrivalTime, int processTime)
{   
    /*  
        The function is used to schedule the processes. If a process is reached the function it will be scheduled by the function
        according to the rules which is defined below.

            1) All process types have their own time slice (quantum). When running a process, If the scheduler reachs the time slice 
                (quantum) of the running process, the process will be preempted and put back to the queue.
            2) if a process that has higher priority comes, the running process will be preempted and put back to the queue.
            3) if a process that has less or same priority with running process comes, the running process will continue to run. 
                The new process will be put back to the queue.
            4) If running process and new process have same priority and they are put back to the queue, the new process will 
                be put back to the queue first.
    */

    // This function used when there is a new process that arrived.

    // Initialize a new ProcessRep pointer by given parameters, 
    // to push it to appropriate FIFO or to send it to the CPU.
    ProcessRep* p = new ProcessRep(type, id, arrivalTime, processTime); 

    // set a temp pointer to NULL, so we can initialize it later 
    // when we need while pushing a process that reaches time limit in the CPU. 
    ProcessRep* p_temp = NULL; 
    
    // check if CPU empty?
    if(this->getRunningProcess() != NULL){
        // check if the running process is executed for the given ProcessTime
        // If it is, send it to the finishedProcess FIFO and set the running process to NULL
        if (this->getRunningProcess()->getProcessTime() == 0){   
            pCpuObj->getFinishedProcess()->queue(this->getRunningProcess());
            this->getRunningProcess()->endTime = totalTime;
            this->setRunningProcess(NULL);
        }
        // check if the running process is executed for the time limit
        // If it is, do (p_temp = running process) and set the running process to NULL
        else if(this->getRunningProcess()->remainingTime == 0){ // checkTimeSlice()
            p_temp = this->getRunningProcess();
            this->setRunningProcess(NULL);
        }
    }
    // Execute newcoming process
    // push coming process to appropriate FIFO at the scheduler
    // If the running process is NULL, pop a process and send it to the CPU.
    // If any process is sent to the CPU, set timeSliceCount to zero.
    if(this->getRunningProcess() == NULL){
        this->pushProcess(p);
        if (p_temp != NULL)
            this->pushProcess(p_temp);
        ProcessRep* p_popped = this->popProcess();
        this->sendProcessToCPU(p_popped);
        timeSliceCount = 0;
    }
    // If running process is continued being executed,
    // Check p has more priority than the running process
    // If p has more priority, push runnning process and send the p to the CPU.
    // pushing running process first and then sending p is critical not to lose currently running process. 
    else{
        // If p is A-type process, it has more priority than non-A-type processes, so we will check that.
        if (p->getProcessType() == "A"){
            if (this->getRunningProcess()->getProcessType() != "A"){
                this->pushProcess(this->getRunningProcess());
                this->sendProcessToCPU(p);
                timeSliceCount = 0;
            }
            
            else{ // p has less or equal priority, so no need to change the running process.
                  // Since p is pushed, timeSliceCount is increased by 1.
                this->pushProcess(p);
                timeSliceCount++;
            }
        }
        // If p is B-type process, it has more priority than C-type processes, so we will check that.
        else if (p->getProcessType() == "B"){
            if (this->getRunningProcess()->getProcessType() == "C"){
                this->pushProcess(this->getRunningProcess());
                this->sendProcessToCPU(p);
                timeSliceCount = 0;
            }
            else{ // p has less or equal priority, so no need to change the running process. Since p is pushed, timeSliceCount is increased by 1.
                this->pushProcess(p);
                timeSliceCount++;
            }
        }
        // p is a C-type process, so it has not more priority than any process type, no need to change the running process
        // Since p is pushed, timeSliceCount is increased by 1.
        else{
            this->pushProcess(p);
            timeSliceCount++;
        }

    }
    // Run the CPU one step with predetermined running process
    this->pCpuObj->runCPU(this->getRunningProcess(), totalTime);
    // check if the running process is executed for the given ProcessTime 
    // If running process is finished, set it as finished process
    if (this->getRunningProcess()->getProcessTime() == 0){     
        pCpuObj->getFinishedProcess()->queue(this->getRunningProcess());
        this->getRunningProcess()->endTime = totalTime+1; // If the process is finished, set time end time as next time. (I increased total time after this step, so we need +1) 
        this->setRunningProcess(this->popProcess());
    }
    // increase total time
    totalTime++;
}

void SchedulerRep::schedule(ProcessRep* p)
{   
    /*  
        The function is used to schedule the processes. If a process is reached the function it will be scheduled by the function
        according to the rules which is defined below.

            1) All process types have their own time slice (quantum). When running a process, If the scheduler reachs the time slice 
                (quantum) of the running process, the process will be preempted and put back to the queue.
            2) if a process that has higher priority comes, the running process will be preempted and put back to the queue.
            3) if a process that has less or same priority with running process comes, the running process will continue to run. 
                The new process will be put back to the queue.
            4) If running process and new process have same priority and they are put back to the queue, the new process will 
                be put back to the queue first.


    */

    // This function used when there is no new process that arrived. 
    if(this->getRunningProcess() != NULL){
        // check if the running process is executed for the given ProcessTime 
        // If running process is ran out of process time, set it as finished process.
        if (this->getRunningProcess()->getProcessTime() == 0){   
            pCpuObj->getFinishedProcess()->queue(this->getRunningProcess());
            this->getRunningProcess()->endTime = totalTime;
            this->setRunningProcess(NULL);
        }
        // check if running process ran out of the execution time in CPU (2, 4 or 8)(2^l)
        // If it reaches time limit, push it to FIFO and set running process to NULL. 
        else if(this->getRunningProcess()->remainingTime == 0){ // checkTimeSlice()
            this->pushProcess(this->getRunningProcess());
            this->setRunningProcess(NULL);
        }
    }
    // If running process is NULL, pop a new process.
    // If there is no process in FIFOs, pop will return NULL pointer,
    // If it is NULL, terminate the scheduling. If it is not, send it to the CPU.
    if(this->getRunningProcess() == NULL){
        ProcessRep* p_popped = this->popProcess();
        if (p_popped == NULL)
            return;
        this->sendProcessToCPU(p_popped);
        timeSliceCount = 0;
    }
    // Run the CPU one step with predetermined running process
    this->pCpuObj->runCPU(this->getRunningProcess(), totalTime);
    // check if the running process is executed for the given ProcessTime 
    // If running process is finished, set it as finished process
    if (this->getRunningProcess()->getProcessTime() == 0){     
        pCpuObj->getFinishedProcess()->queue(this->getRunningProcess());
        this->getRunningProcess()->endTime = totalTime+1;
        this->setRunningProcess(this->popProcess());
    }
    // increase total time
    totalTime++;    
}
