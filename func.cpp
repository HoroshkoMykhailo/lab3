#include "func.h"
int input:: getnum(string coor, string s){
    int c;
    char ch;
    cout<< "Enter the " + coor + " coordinate of the " + s + " point: ";
    while (!(cin >> c) || !(cin.get(ch)) || ch != '\n' || c <= 0 || c >= 32000) {
        cin.clear();
        cout << "Incorrect value. Enter the " + coor + " coordinate of the " + s + " point: ";
    }
    return c;
}
vector<int> input:: getpoints(graph& gr){
    vector<int> points;
    char ch;
    int c;
    bool er;
    do{
        er = false;
        do{
            er = false;
            //DRY
            points.push_back(getnum("x", "start"));
            points.push_back(getnum("y", "start"));
            try{
                gr.findnode(points[0] - 1, points[1] - 1);
            }
            catch(const invalid_argument& e){
                cout<< e.what();
                er = true;
                points.erase(points.end() - 2, points.end());
            }
        }while(er);
        do{
            er = false;
            points.push_back(getnum("x", "end"));
            points.push_back(getnum("y", "end"));
            try{
                gr.findnode(points[2] - 1, points[3] - 1);
            }
            catch(const invalid_argument& e){
                cout<< points[3] << " "<< points[2];
                cout<< e.what();
                er = true;
                points.erase(points.end() - 2, points.end());
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
bool input:: choose(){
    int c;
    cout << "Which algorithm do you want to use(Esc for Dijkstra, any key for A*): ";
    c = (int)_getch();
    cout << endl;
    bool r = (c == 27);
    return r;
}