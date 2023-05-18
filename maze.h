#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class maze{
    vector<vector<char>> m;
    string fname;
public:
    maze(string);
    void fillmaze();
    void line_to_maze_row(string, int);
    char getcell(int, int);
    int getrows();
    int getcol();
};
class checker{
    int n = 0;
public:
    bool two_chars_line(string, lines_error&);
};