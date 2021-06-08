# include<iostream>
# include<iomanip>
# include<vector>
# define SPACE_FILL 0
# define VERBOSE true
using namespace std;
enum Direction{
    Up,Down,Left,Right,
};
class Site{
private:

public:
    int row;
    int col;
    Site(){
        row=0;
        col=0;
    }
    Site(int r,int c){
        row=r;
        col=c;
    }


};
class Board
{
private:
    Site space;

public:
    vector<vector<int>> board;
    int size_max;
    int size_min;
    bool possible_direct[4];
    string info[4]={"up","down","left","right"};
    void init();
    Board(int);
    void print();
    void possible_direction();
    void exec_direction(int direction);
    ~Board();

};