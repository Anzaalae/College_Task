#include "10-3Queue.h"

void Queue::enqueue(int value) {
    pushBack(value);
}
    
int Queue::dequeue() {
    return popFront();
}
    
bool Queue::empty() const {
    return length() == 0;
}