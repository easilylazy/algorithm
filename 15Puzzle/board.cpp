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
    target=board;
}
void Board::init(){
    
}
void Board::print(){
    print(board);
}
void Board::print(board_type board){
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
    if(VERBOSE){
        for(int i=0;i<4;i++){
            if(possible_direct[i]==true){
                cout<<info[i]<<" is possible"<<endl;
            }
        }
    }
    
}
void Board::exec_direction(int direction){
    exec_direction(board,direction);
}
void Board::exec_direction(board_type &board,int direction){
    if(VERBOSE){
        cout<<"go "<<info[direction]<<endl;
    }
    switch (direction)
    {
    case Up:
        board[space.row][space.col]=board[space.row-1][space.col];
        board[space.row-1][space.col]=SPACE_FILL;
        space.row-=1;
        break;
    case Down:
        board[space.row][space.col]=board[space.row+1][space.col];
        board[space.row+1][space.col]=SPACE_FILL;
        space.row+=1;
        break;
    case Left:
        board[space.row][space.col]=board[space.row][space.col-1];
        board[space.row][space.col-1]=SPACE_FILL;
        space.col-=1;
        break;
    case Right:
        board[space.row][space.col]=board[space.row][space.col+1];
        board[space.row][space.col+1]=SPACE_FILL;
        space.col+=1;
        break;
    
    default:
        break;
    }
}
void Board::BFS(){
    queue<board_type> open;
    open.push(board);
    board_type present;
    int cnt=0;
    while(!open.empty()){
        cnt++;
        if(cnt>3){
            break;
        }
        board=open.front();
        present=board;
        possible_direction();
        // for specific state 
        for(int i=0;i<4;i++){
            board=present;
            if(possible_direct[i]){
                exec_direction(board,i);
                records[make_pair(present,i)]=board;
                // add new appearance
                if(visited.find(board)==visited.end()){
                    open.push(board);
                }
            }
        }
        visited[board]=true;
        
    }
}
void Board::display(){
    for(auto item: records){
        
        cout<<item.first.second<<endl;
    }
}
Board::~Board()
{
}