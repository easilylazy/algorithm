# include"include/board.h"
# include<stack>
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
Site Board::locate_space(){
    return locate_space(board);
}
Site Board::locate_space(board_type board){
    for(int i=0;i<=size_max;i++){
        for(int j=0;j<=size_max;j++){
            if(board[i][j]==SPACE_FILL){
                return Site(i,j);
            }
        }
    } 
    return Site(0,0);
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
void Board::exec_direction(int direction,Site &space){
    exec_direction(board,direction,space);
}
void Board::exec_direction(board_type &board,int direction,Site &space){
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
void Board::shuffle(int steps){
    space=locate_space(board);
    for(int i=0;i<steps;i++){
        possible_direction();

        int direct=rand()%4; 
        while(possible_direct[direct]!=true){
            direct=rand()%4;
        }
        exec_direction(direct,space);
    }
    print(board);
    start=board;
}
void Board::path(){
    board=start;
    int max_step=30;
    stack<direct_type> store;
    map<board_type,bool> pass;
    board_type next;
    pass[board]=true;
    while(board!=target){

        if(max_step--<0){
            cout<<"failed"<<endl;
            break;
        }
        for(auto item:records){
            if(item.second==board&&pass.find(item.first.first)==pass.end()){
                store.push(item.first.second);
                print(board);
                cout<<info[item.first.second]<<endl;
                board=item.first.first;
                pass[board]==true;
                // break;
            }
        }
    }
    while(!store.empty()){
        cout<<info[store.top()]<<endl;
        store.pop();

    }
}
void Board::BFS(){
    queue<board_type> open;
    open.push(start);
    board_type present;
    Site temp_space;
    int cnt=0;
    while(!open.empty()){
        // cnt++;
        // if(cnt>30){
        //     break;
        // }
        board=open.front();
        if(board==target){
            break;
        }
        present=board;
        // for specific state 
        temp_space=locate_space(board);
        space=temp_space;
        possible_direction();

        for(int i=0;i<4;i++){
            
            if(possible_direct[i]){
                board=present;
                temp_space=space;
                exec_direction(board,i,temp_space);
                records[make_pair(present,i)]=board;
                // add new appearance
                if(visited.find(board)==visited.end()){
                    open.push(board);
                }
                // mapping[board]=present;
            }
        }
        visited[board]=true;
        open.pop();
        
    }
}
void Board::display(){
    for(auto item: records){
        cout<<"before"<<endl;
        print(item.first.first);
        
        cout<<item.first.second<<endl;
        cout<<"after"<<endl;
        print(item.second);
    }
}
Board::~Board()
{
}