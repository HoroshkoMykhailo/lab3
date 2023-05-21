#include "Node.h"
Node:: Node(int i, int j):x(i), y(j){
    priority = 0;
}
void Node:: setp(int p){
    priority = p;
}
int Node:: getp(){
    return priority;
}
void Node:: add_adj(Node* neighbor){
    adj.push_back(neighbor);
}
vector<Node*>&  Node:: get_adj(){
    return adj;
}
int Node:: getX(){
    return x;
}
int Node:: getY(){
    return y;
}