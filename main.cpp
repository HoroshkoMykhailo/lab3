#include "graph.h"
#include "func.h"
int main(int argc, char* argv[]){
    try{
        string name = "C:\\Visual studio\\codes\\3\\";
        name.append(argv[1]);
        maze puzzle(name);
        puzzle.fillmaze();
        graph gr(puzzle);
        vector<int> points = getpoints();
        puzzle.changemaze(gr.Dijkstra(points[0] - 1, points[1] - 1, points[2] - 1, points[3] - 1));
        puzzle.printmaze();
    }
    catch(const invalid_argument& e){
        cerr<< e.what();
    }
    catch(lines_error& errors){
        for(int i = 0; i < errors.message().size(); i++){
            cerr << errors.what() << errors.message()[i] << endl;
        }
    }
}