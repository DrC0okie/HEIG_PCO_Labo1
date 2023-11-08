/**
 * @author Timothée Van Hove
 */

#include "mythread.h"
#include "yieldlock.h"

// Global variables accessed (read/write) by all the threads
static volatile long unsigned int counter;
static  YieldLock yLock;


void runTask(unsigned long nbIterations)
{
    long unsigned int i = 0;

    while (i < nbIterations)
    {
        yLock.lock();
        ++counter;
        yLock.unlock();
        i++;
    }
}

void initCounter()
{
    counter = 0;
}

long unsigned int getCounter()
{
    return counter;
}
