# include"include/board.h"
# include<stack>
Board::Board(int size=4)
{
    this->size=size;
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
    board[size_max][size_max]=SPACE_FILL;
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
    start=board;
}
void Board::modStart(board_type board){
    this->board=board;
    start=board;
}
void Board::path(){
    board=target;
    record_type next;
    int max_step=30;
    stack<direct_type> confirm_path;
    stack<board_type> confirm_state;
    while(board!=start){
        if(max_step--<0){
            cout<<"failed"<<endl;
            return;
        }
        next=useful[board];
        // cout<<info[next.second]<<endl;
        // print(next.first);
        board=next.first;
        confirm_state.push(next.first);
        confirm_path.push(next.second);

    }
    max_step=0;
    while(!confirm_path.empty()){
        print(confirm_state.top());
        cout<<"step "<<++max_step<<" "<<info[confirm_path.top()]<<endl;
        confirm_state.pop();
        confirm_path.pop();
    }
    print(target);
}
cost_type Board::difference(board_type present){
    cost_type difference=0;
    for(int row=0;row<size;row++){
        for(int col=0;col<size;col++){
            if(target[row][col]!=present[row][col]){
                difference++;
            }
        }
    }  
    return difference;
}
void Board::simple(){

    priority_queue<open_simple_type,vector<open_simple_type>,greater<open_simple_type>> open;

    int depth;
    vector<int> costs(3);// depth;heuristic;total
    int heuristic=difference(start);
    costs={0,heuristic,heuristic};
    open.push(open_simple_type(start,costs));
    // heuristic_type closed;
    board_type present;
    Site temp_space;
    int cnt=0;
    while(!open.empty()){
        cnt++;
        if(cnt>1000){
            cout<<"over steps"<<endl;
            break;
        }
        board =open.top().board;
        depth =open.top().costs[0];
        
        if(board==target){
            cout<<"achieve target"<<endl;
            break;
        }
        present=board;
        // for specific state 
        temp_space=locate_space(board);
        space=temp_space;
        possible_direction();

        if(VERBOSE){
            cout<<"----------optimize-------"<<endl;
            print(board);
            cout<<endl;
            cout<<"d: "<<depth<<" h: "<<open.top().costs[1]<<" loss"<< open.top().costs[2]<<endl;
        }
        open.pop();
        for(int i=0;i<4;i++){
            
            if(possible_direct[i]){
                board=present;
                temp_space=space;
                exec_direction(board,i,temp_space);
                records[make_pair(present,i)]=board;
                // closed_simple[make_pair()]
                // add new appearance
                if(visited.find(board)==visited.end()){
                    
                    heuristic=difference(board);
                    costs={depth+1,heuristic,depth+1+heuristic};
                    open.push(open_simple_type(board,costs));
                    if(VERBOSE){
                        cout<<"----------update-------"<<endl;
                        print(board);
                        cout<<endl;
                        cout<<"d: "<<costs[0]<<" h: "<<costs[1]<<" loss"<< costs[2]<<endl;
                    }       
                    
                }
                if(useful.find(board)==useful.end()){
                    useful[board]=make_pair(present,i);
                }
            }
        }
        visited[present]=true;
        
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
            cout<<"achieve target"<<endl;
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
                if(useful.find(board)==useful.end()){
                    useful[board]=make_pair(present,i);
                }
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