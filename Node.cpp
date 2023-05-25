#include "Node.h"
Node:: Node(int i, int j):x(i), y(j){
    priority = 0;
}
Node:: ~Node(){
    for (int i = 0; i < adj.size(); i++){
        if(adj[i] != nullptr)  adj[i] = nullptr;
    }
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