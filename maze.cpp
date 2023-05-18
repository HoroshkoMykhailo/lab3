#include "maze.h"
#include "except_classes.h"
maze:: maze(string name):fname(name){
}
void maze:: fillmaze(){
    ifstream file(fname);
    if(!file.is_open()){
        throw invalid_argument("File doesn`t exist");
    }
    string line;
    checker check;
    lines_error er;
    getline(file, line);
    int n = line.size();
    if(!check.two_chars_line(line, er)){
        line_to_maze_row(line, n);
    }
    while(getline(file, line)){
        if(line.size() != n){
            throw invalid_argument("File does not consist of maze");
        }
        if(!check.two_chars_line(line, er)){
            line_to_maze_row(line, n);
        }
    }
    if(!er.is_empty()){
        throw er;
    }
}
char maze:: getcell(int i, int j){
    return m[i][j];
}
int maze:: getrows(){
    return m.size();
}
int maze:: getcol(){
    return m[0].size();
}
void maze:: line_to_maze_row(string line, int n){
    vector<char> l;
    for(int i = 0; i<n; i++){
        l.push_back(line[i]);
    }
    m.push_back(l);
}
bool checker:: two_chars_line(string line, lines_error& er){
    n++;
    bool r = true;
    for(int i = 0; i < line.size(); i++){
        if(line[i] != ' ' && line[i] != '#'){
            string s = "There is a char which is not # or ' ' In line number " + to_string(n + 1) + " in cell number " + to_string(i + 1);
            er.addMessage(s);
            r = false;
        }
    }
    return r;
}