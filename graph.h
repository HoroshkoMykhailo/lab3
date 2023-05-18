#include "maze.h"
class Node{
    int x, y;
    vector<Node*> adj;
public:
    Node(int, int);
    void add_adj(Node*);
    vector<Node*>& get_adj();
};
class graph{
    vector<vector<Node*>> g;
public:
    graph(maze&);
};