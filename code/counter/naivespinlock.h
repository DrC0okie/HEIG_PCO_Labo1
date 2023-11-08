#ifndef NAIVESPINLOCK_H
#define NAIVESPINLOCK_H

/**
 * @file naivespinlock.h
 * @date 01.10.2023
 * @brief Implementation of a super naive SpinLock without atomic operations.
 * @details the threads are spinning in a loop until they acquire the lock.
 * @author Timothée Van Hove
 */
class NaiveSpinLock
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
    volatile bool locked = false;
};

#endif // NAIVESPINLOCK_H
