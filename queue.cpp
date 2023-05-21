#include "queue.h"

Queue::Queue(int n)
{
    arr = new Node*[n];
    capacity = n;
    front = 0;
    last = -1;
    size = 0;
}
 
Queue::~Queue() {
    delete[] arr;
}
 
Node* Queue::pop()
{
    Node* x = arr[front];
 
    front = (front + 1) % capacity;
    size--;
 
    return x;
}
 
void Queue::push(Node* item)
{
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