#pragma once
#include <iostream>
#include <fstream>
#include "Node.h"
#include "except_classes.h"
using namespace std;
class maze{
    vector<vector<char>> m;
    string fname;
public:
    maze(string);
    void fillmaze();
    void line_to_maze_row(string, int);
    char getcell(int, int);
    void changemaze(vector<Node*>);
    void printmaze();
    int getrows();
    int getcol();
};
class checker{
    int n;
public:
    checker();
    bool two_chars_line(string, lines_error&);
};