#pragma once
#include "except_classes.h"
#include "graph.h"
class Queue
{
    Node **arr;
    int capacity;
    int front; 
    int last; 
    int size; 
 
public:
    Queue(int);
    ~Queue();                
    void push(Node*);
    Node* pop();
    int getsize();
    bool isEmpty();
    bool isFull();
};