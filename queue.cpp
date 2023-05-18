#include "queue.h"

Queue::Queue(int n)
{
    arr = new Node*[n];
    capacity = size;
    front = 0;
    last = -1;
    size = 0;
}
 
Queue::~Queue() {
    delete[] arr;
}
 
Node* Queue::peek()
{
    if (isEmpty())
    {
        throw underflow_error("Underflow\nProgram Terminated\n");
    }
 
    Node* x = arr[front];
 
    front = (front + 1) % capacity;
    size--;
 
    return x;
}
 
void Queue::push(Node* item)
{
    if (isFull())
    {
        throw overflow_error("Overflow\nProgram Terminated\n");
    }
    last = (last + 1) % capacity;
    arr[last] = item;
    size++;
}

int Queue::getsize() {
    return size;
}
 
bool Queue::isEmpty() {
    return (size == 0);
}
 
bool Queue::isFull() {
    return (size == capacity);
}