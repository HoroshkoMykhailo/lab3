#include "graph.h"
Node:: Node(int i, int j):x(i), y(j){}
void Node:: add_adj(Node* neighbor){
    adj.push_back(neighbor);
}
vector<Node*>&  Node:: get_adj(){
    return adj;
}
graph:: graph(maze& m){
    int rows = m.getrows();
    int cols = m.getcol();
    g.resize(rows, std::vector<Node*>(cols, nullptr));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (m.getcell(i, j) != '#') {
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