# include"include/board.h"

Board::Board(int size=4)
{
    size_max=size-1;
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
void Board::print(){
    for(auto row:board){
        for(auto item:row){
            cout<<setw(5)<<item<<' ';
        }
        cout<<endl;
    }
}
Board::~Board()
{
}