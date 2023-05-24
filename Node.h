#pragma once
#include <vector>
using namespace std;
class Node{
    int x, y;
    vector<Node*> adj;
    int priority;
public:
    Node(int, int);
    ~Node();
    void setp(int);
    int getp();
    int getX();
    int getY();
    void add_adj(Node*);
    vector<Node*>& get_adj();
};