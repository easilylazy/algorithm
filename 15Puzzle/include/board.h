# include<iostream>
# include<iomanip>
# include<vector>
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
    vector<vector<int>> board;
    Site space;

public:
    int size_max;
    int size_min;
    bool possible_direct[4];
    string info[4]={"up","down","left","right"};
    void init();
    Board(int);
    void print();
    void possible_direction();
    ~Board();

};