#include "yieldlock.h"

void YieldLock::lock(){
    while(locked.exchange(true, std::memory_order_acquire)){
        // Here we hint the scheduler that we are waiting for the lock
        // and that this thread can be preempted to allow other threads to run
        // so the time allowed by the scheduler is not waisted just spinning.
        std::this_thread::yield();
    }
}

void YieldLock::unlock(){
    locked.store(false, std::memory_order_release);
}
