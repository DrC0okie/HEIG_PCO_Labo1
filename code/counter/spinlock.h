#ifndef SPINLOCK_H
#define SPINLOCK_H

#include <atomic>

/**
 * @file spinlock.h
 * @date 01.10.2023
 * @brief Implementation of a super simple SpinLock with atomic operations.
 * @details the threads are spinning in a loop until they acquire the lock.
 * @author Timothée Van Hove
 */
class SpinLock
{
public:

    /**
     * @brief locks the access to the locked flag
     * If the lock is held by another thread, just waits (spin)
     */
    void lock();

    /**
     * @brief unlocks the access to the locked flag to other threads
     */
    void unlock();

private:
    std::atomic<bool> locked = {false};
};

#endif // SPINLOCK_H
