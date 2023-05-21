#pragma once
#include <vector>
using namespace std;
class Node{
    int x, y;
    vector<Node*> adj;
public:
    Node(int, int);
    int getX();
    int getY();
    void add_adj(Node*);
    vector<Node*>& get_adj();
};