#include "func.h"
vector<int> getpoints(){
    vector<int> points;
    int c;
    cout<< "Enter the x coordinate of start point: ";
    cin >> c;
    points.push_back(c);
    cout << "Enter the y coordinate of start point: ";
    cin >> c;
    points.push_back(c);
    cout << "Enter the x coordinate of end point: ";
    cin >> c;
    points.push_back(c);
    cout << "Enter the y coordinate of end point: ";
    cin >> c;
    points.push_back(c);
    return points;              
}