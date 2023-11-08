#ifndef TICKETLOCK_H
#define TICKETLOCK_H

/**
 * @file ticketLock.h
 * @date 01.10.2023
 * @brief Implementation of a TicketLock.
 * @details When a thread wants the lock, it first gets a ticket, then spins until
 * it is its turn to hold the lock.
 * This ensures that threads get the lock in the order the requested it
 * @author Timothée Van Hove
 */

#include <atomic>
#include <thread>
#include "stdlib.h"

class TicketLock
{
public:

    /**
     * @brief TicketLock::lock Acquiring the lock by testing if the thread's ticket number equals the current ticket number
     */
    void lock();

    /**
     * @brief Releasing the lock by incrementing the current ticket
     */
    void unlock();

private:
    // ticket number of the thread that is currently allowed to hold the lock
    std::atomic<size_t> currentTicket = {0};

    // ticket number thet the next thread trying to get the lock will take
    std::atomic<size_t> nextTicket = {0};
};

#endif // TICKETLOCK_H
