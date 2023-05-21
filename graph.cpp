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
Node* graph:: findnode(int x1, int y1){
    if(g[x1][y1] == nullptr){
        throw invalid_argument("The given point is incorrect");
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