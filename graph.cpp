#include "graph.h"
graph:: graph(maze& m){
    int rows = m.getrows();
    int cols = m.getcol();
    g.resize(rows, vector<Node*>(cols, nullptr));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (m.getcell(i, j) != 'X') {
                g[i][j] = new Node(i, j);
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (g[i][j] != nullptr) {
                if (i > 0 && g[i - 1][j] != nullptr) {
                    g[i][j]->add_adj(g[i - 1][j]);
                }
                if (j > 0 && g[i][j - 1] != nullptr) {
                    g[i][j]->add_adj(g[i][j - 1]);
                }
                if (i < rows - 1 && g[i + 1][j] != nullptr) {
                    g[i][j]->add_adj(g[i + 1][j]);
                }
                if (j < cols - 1 && g[i][j + 1] != nullptr) {
                    g[i][j]->add_adj(g[i][j + 1]);
                }
            }
        }
    }
}
graph:: ~graph(){
    for(int i =0; i < g.size(); i++){
        for(int j = 0; j < g[0].size(); j++){
            delete g[i][j];
        }
    }
}
Node* graph:: findnode(int x1, int y1){
    if(g[x1][y1] == nullptr || (x1 >g.size() || y1 > g[0].size())){
        throw invalid_argument("The given point is incorrect\n");
    }
    return g[x1][y1];
}
vector<Node*> graph:: Dijkstra(int x1, int y1, int x2, int y2){
    Node* start = findnode(x1, y1), *end = findnode(x2, y2);
    Queue q(g.size()*g[0].size());
    vector<Node*> prev(g.size() * g[0].size(), nullptr);
    q.push(start);
    while (!q.isEmpty()) {
        Node* current = q.pop();
        if (current == end) {
            break;
        }
        vector<Node*>& adjac = current->get_adj();
        for (int i = 0; i < adjac.size(); i++) {
            Node* neighbor = adjac[i];
            int ind = neighbor->getX() * g[0].size() + neighbor->getY();
            if (prev[ind] == nullptr) {
                prev[ind] = current;
                q.push(neighbor);
            }
        }
    }
    if (prev[end->getX() * g[0].size() + end->getY()] == nullptr) {
        return std::vector<Node*>();
    }
    std::vector<Node*> path;
    Node* current = end;
    while(current != start){
        path.insert(path.begin(), current);
        current = prev[current->getX() * g[0].size() + current->getY()];
    }
    path.insert(path.begin(), start);
    return path;
}
vector<Node*> graph:: Astar(int x1, int y1, int x2, int y2){
    Node* start = findnode(x1, y1), *end = findnode(x2, y2);
    priorityQueue q;
    vector<Node*> prev(g.size() * g[0].size(), nullptr);
    vector<int> gscore(g.size() * g[0].size(), g.size() * g[0].size());
    gscore[start->getX() * g[0].size() + start->getY()] = 0;
    start->setp(heuristic(start, end));
    q.push(start);
    while (!q.isEmpty()) {
        Node* current = q.pop();
        if (current == end) {
            break;
        }
        vector<Node*>& adjac = current->get_adj();
        for (int i = 0; i < adjac.size(); i++) {
            Node* neighbor = adjac[i];
            int ind = neighbor->getX() * g[0].size() + neighbor->getY();
            int tentativeGScore = gscore[current->getX() * g[0].size() + current->getY()] + 1;
            if (tentativeGScore < gscore[ind]) {
                prev[ind] = current;
                gscore[ind] = tentativeGScore;
                neighbor->setp(tentativeGScore + heuristic(neighbor, end));
                if (!q.isin(neighbor)) {
                    q.push(neighbor);
                }
            }
        }
    }
    if (prev[end->getX() * g[0].size() + end->getY()] == nullptr) {
        return std::vector<Node*>();
    }
    std::vector<Node*> path;
    Node* current = end;
    while(current != start){
        path.insert(path.begin(), current);
        current = prev[current->getX() * g[0].size() + current->getY()];
    }
    path.insert(path.begin(), start);
    return path;
}

int heuristic(Node* s, Node* goal){
    int dx = abs(s->getX() - goal->getX());
    int dy = abs(s->getY() - goal->getY());
    return dx + dy;
}