#ifndef QUEUE_H
#define QUEUE_H

#include "10-3List.h"

class Queue : public List {
public:
    void enqueue(int value);
    
    int dequeue();
    
    bool empty() const;
};

#endif