#ifndef YIELDLOCK_H
#define YIELDLOCK_H

/**
 * @file yieldlock.h
 * @date 01.10.2023
 * @brief Implementation of a YieldLock.
 * @details Like a SpinLock, but instead on spinning, it gives its time slice back to the scheduler
 * This prevents the CPU waisting resources for just spinning.
 * @author Timothée Van Hove
 */

#include <atomic>
#include <thread>

class YieldLock
{
public:

    /**
     * @brief Essentially the same implementation as the SpinLock::lock()
     * @details The only difference id that instead of spinning, the lock yields its time slice back to the scheduler
     */
    void lock();

    void unlock();

private:
    std::atomic<bool> locked = {false};
};

#endif // YIELDLOCK_H
