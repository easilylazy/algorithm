# include"include/board.h"

Board::Board(int size=4)
{
    size_max=size-1;
    size_min=0;
    board = vector<vector<int>>(size);
    for(int row=0;row<size;row++){
        vector<int> row_content;
        row_content=vector<int>(size);
        for(int col=0;col<size;col++){
            row_content[col]=row*size+col+1;
        }
        board[row]=row_content;
    }   
    board[size_max][size_max]=0;
    space.col=size_max;
    space.row=size_max;
}
void Board::init(){
    
}
void Board::print(){
    for(auto row:board){
        for(auto item:row){
            cout<<setw(5)<<item<<' ';
        }
        cout<<endl;
    }
}
void Board::possible_direction(){
    for(int i=0;i<4;i++){
        possible_direct[i]=true;
    }
    if(space.row==size_max){
        possible_direct[Down]=false;
    }else if(space.row==size_min){
        possible_direct[Up]=false;
    }
    if(space.col==size_max){
        possible_direct[Right]=false;
    }else if(space.col==size_min){
        possible_direct[Left]=false;
    }
    for(int i=0;i<4;i++){
        if(possible_direct[i]==true){
            cout<<info[i]<<" is possible"<<endl;
        }
    }
}
Board::~Board()
{
}