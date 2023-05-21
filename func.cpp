#include "func.h"
#include <conio.h>
vector<int> getpoints(graph& gr){
    vector<int> points;
    char ch;
    int c;
    bool er;
    do{
        er = false;
        do{
            er = false;
            cout<< "Enter the x coordinate of the start point: ";
            while (!(cin >> c) || !(cin.get(ch)) || ch != '\n' || c <= 0 || c >= 32000) {
                cin.clear();
                cout << "Incorrect value. Enter the x coordinate of the start point: ";
            }
            points.push_back(c);
            cout << "Enter the y coordinate of the start point: ";
            while (!(cin >> c) || !(cin.get(ch)) || ch != '\n' || c <= 0 || c >= 32000) {
                cin.clear();
                cout << "Incorrect value. Enter the y coordinate of the start point: ";
            }
            points.push_back(c);
            try{
                gr.findnode(points[0] - 1, points[1] - 1);
            }
            catch(const invalid_argument& e){
                cout<< e.what();
                er = true;
            }
            if(er){
                points.erase (points.end() - 2, points.end());
            }
        }while(er);
        do{
            er = false;
            cout<< "Enter the x coordinate of the end point: ";
            while (!(cin >> c) || !(cin.get(ch)) || ch != '\n' || c <= 0 || c >= 32000) {
                cin.clear();
                cout << "Incorrect value. Enter the x coordinate of the end point: ";
            }
            points.push_back(c);
            cout << "Enter the y coordinate of the end point: ";
            while (!(cin >> c) || !(cin.get(ch)) || ch != '\n' || c <= 0 || c >= 32000) {
                cin.clear();
                cout << "Incorrect value. Enter the y coordinate of the end point: ";
            }
            points.push_back(c);
            try{
                gr.findnode(points[0] - 1, points[1] - 1);
            }
            catch(const invalid_argument& e){
                cout<< e.what();
                er = true;
            }
            if(er){
                points.erase (points.end() - 2, points.end());
            }
        }while(er);
        if(points[0] == points[2] && points[1] == points[3]){
            cout << "You entered 2 identical points" << endl;
            er = true;
            points.erase (points.begin(), points.end());
        }
    }while(er);
    return points;              
}
bool c_alg(){
    int c;
    cout << "Which algorithm do you want to use(Esc for Dijkstra, any key for A*): ";
    c = (int)_getch();
    bool r = (c == 27);
    return r;
}