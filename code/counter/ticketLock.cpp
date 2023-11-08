#include "ticketLock.h"

void TicketLock::lock(){
    size_t ticket = nextTicket.fetch_add(1, std::memory_order_relaxed);
    while(currentTicket.load(std::memory_order_acquire)!= ticket){
        // Here we hint the scheduler that we are waiting for the lock
        // and that this thread can be preempted to allow other threads to run
        // so the time allowed by the scheduler is not waisted just spinning.
        std::this_thread::yield();
    }
}

void TicketLock::unlock(){
    currentTicket.fetch_add(1, std::memory_order_release);
}
