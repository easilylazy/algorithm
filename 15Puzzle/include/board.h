# include<iostream>
# include<iomanip>
# include<vector>
# include<map>
# include<queue>
# define SPACE_FILL 0
# define VERBOSE false//true
# define MAXSTEPS 40000000
using namespace std;
typedef vector<vector<int>> board_type;
typedef int direct_type;
typedef int cost_type;
// typedef int total_type;// first: depth second: heuristic
typedef pair<board_type,cost_type> info_type;
typedef pair<board_type,direct_type> record_type;
typedef pair<record_type,cost_type> heuristic_type;
struct open_simple_type 
{
    board_type board;
    vector<int> costs;

    open_simple_type(board_type board,vector<int> costs) {this->board=board;this->costs=costs;}
    bool operator>(const open_simple_type& a) const
    {
        return costs[2] > a.costs[2]; //小顶堆
    }
};
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
    Site operator-(const Site& a)const{
        return Site(row-a.row,col-a.col);
    }
    bool operator==(const Site& a)const{
        if(row==a.row){
            return true;
        }else{
            return false;
        }
    }


};
class Board
{
private:
    Site space;

public:
    vector<vector<int>> board;
    vector<vector<int>> target;
    vector<vector<int>> start;
    map<heuristic_type,board_type> closed_simple;
    map<record_type,board_type> records;
    map<board_type,record_type> useful;
    map<board_type,bool> visited; 
    int size;
    int size_max;
    int size_min;
    int reverse_rate=3;
    bool possible_direct[4];
    string info[4]={"up","down","left","right"};
    void init();
    Board(int);
    void print(string tips="BOARD");
    void print(board_type board);
    void display();
    Site locate_space(int num=SPACE_FILL);
    Site locate_space(board_type board,int num=SPACE_FILL);
    int locate_site(board_type board,Site x);
    void possible_direction();
    void exec_direction(board_type &board,int direction,Site &space);
    void exec_direction(int direction,Site &space);
    void shuffle(int steps=10);
    void modStart(board_type board);
    void path();
    void BFS();
    void simple();// heuristic: h(x)=difference
    void better(cost_type(Board::*h)(board_type));
    cost_type difference(board_type present);
    cost_type steps(board_type present);
    cost_type reverse(board_type present);
    cost_type difference_reverse(board_type present);
    ~Board();

};