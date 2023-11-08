#include "spinlock.h"

void SpinLock::lock(){
    //Atomically exchange the value of locked with 'true'
    //if the previous value was 'false', the lock was free, and is now acquired
    //if the previous value was 'true', the lock is held, and we now spin (loop)
    while(locked.exchange(true, std::memory_order_acquire)){
        ;
    }
}

void SpinLock::unlock(){
    locked.store(false, std::memory_order_release);
}
