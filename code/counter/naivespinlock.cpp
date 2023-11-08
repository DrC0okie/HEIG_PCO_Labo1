#include "naivespinlock.h"
void NaiveSpinLock::lock(){
    while(locked);
    locked = true;
}

void NaiveSpinLock::unlock(){
    locked = false;
}
