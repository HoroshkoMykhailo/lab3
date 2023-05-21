#include "func.h"
vector<int> getpoints(graph& gr){
    vector<int> points;
    int c;
    cout<< "Enter the x coordinate of start point: ";
    cin >> c;
    points.push_back(c);
    cout << "Enter the y coordinate of start point: ";
    cin >> c;
    points.push_back(c);
    gr.findnode(points[0] - 1, points[1] - 1);
    cout << "Enter the x coordinate of end point: ";
    cin >> c;
    points.push_back(c);
    cout << "Enter the y coordinate of end point: ";
    cin >> c;
    points.push_back(c);
    gr.findnode(points[2] - 1, points[3] - 1);
    if(points[0] == points[2] && points[1] == points[3]){
        throw invalid_argument("You entered 2 identical points");
    }
    return points;              
}
bool c_alg(){
    string c;
    cout << "Which algorithm do you want to use(D for Dijkstra, A for A*): ";
    cin >> c;
    bool r = (c == "D" || c=="d" || c== "Dijkstra" || c == "dijkstra");
    return r;
}