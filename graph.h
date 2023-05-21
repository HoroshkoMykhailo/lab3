#pragma once
#include "maze.h"
#include "queue.h"
class graph{
    vector<vector<Node*>> g;
public:
    graph(maze&);
    Node* findnode(int, int);
    vector<Node*> Dijkstra(int, int, int, int);
};