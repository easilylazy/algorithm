#include<iostream>
#include<vector>
#include<stack>
#include<array>
#define MAX_ROW 9
#define MAX_COL 9
#define FILL_EMPTY 0
using namespace std;
typedef array<int,2> Site;

template <typename T> 

void display(vector<vector<T>> a){
    for(auto e:a){
        for(auto y:e){
            cout<<y<<' ';
        }
        cout<<endl;
    }
        cout<<endl;

}
void print(Site pos){
    cout<<"pos at x: "<<pos[0]<<" y: "<<pos[1]<<endl;
}
                vector<vector<char>> board=
        {
            {'4','.','.','.','.','8','.','5','.'},
            {'.','.','.','.','7','.','2','9','.'},
            {'.','.','.','.','.','.','.','3','.'},
            {'.','.','.','.','.','4','.','.','8'},
            {'.','6','.','.','3','.','.','7','.'},
            {'1','.','.','5','.','.','.','.','.'},
            {'.','9','.','.','.','.','.','.','.'},
            {'.','7','3','.','6','.','.','.','.'},
            {'.','4','.','2','.','.','.','.','5'},
        };
        vector<vector<char>> board2=
        {
            {'.','.','8','1','.','.','.','.','7'},
            {'.','4','7','8','5','.','6','.','.'},
            {'.','5','.','9','.','.','2','.','4'},
            {'7','.','6','2','.','8','.','.','1'},
            {'.','.','1','.','4','.','7','.','.'},
            {'2','.','.','.','7','.','3','.','8'},
            {'4','.','5','.','.','3','.','2','.'},
            {'.','.','2','.','1','9','8','7','.'},
            {'8','.','.','.','.','5','4','.','.'},
        };
// vector<vector<char>> board={{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
vector<vector<int>> eval_board(MAX_ROW,vector<int>(MAX_COL));//={{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
void init(){
    for(int col=0;col<board[0].size();col++){
        for(int row=0;row<board.size();row++){
            if(board[row][col]=='.'){
                eval_board[row][col]=FILL_EMPTY;
            }else{
                eval_board[row][col]=board[row][col]-'0';
            }
        }
    }
}


bool find_possible(Site pos,int bias){
    int pos_row=pos[0],pos_col=pos[1];
    //start from bias, find the smallest solution
    for(int i=bias;i<=MAX_COL;i++){
        bool success=true;
        // judge in row
        for(int col=0;col<MAX_COL;col++){
            if(eval_board[pos[0]][col]==i){
                success=false;
                break;
            }
        }
        if(success==false){
            continue;
        }
        // judge in col
        for(int col=0;col<MAX_COL;col++){
            if(eval_board[col][pos[1]]==i){
                success=false;
                break;
            }
        }
        if(success==false){
            continue;
        }
        // judge in block
        int block_row=3*(pos[0]/3);
        int block_col=3*(pos[1]/3);
        for(int row=0;row<3;row++){
            for(int col=0;col<3;col++){
                if(eval_board[block_row+row][block_col+col]==i){
                success=false;
                    break;
                }
                
            }
            if(success==false){
                break;
            }
        }
        if(success==false){
            continue;
        }else{
            // cout<<"***********"<<endl;
            // cout<<i<<endl;
            // cout<<"***********"<<endl;
            eval_board[pos_row][pos_col]=i;
            return success;
        }
    } 
    return false;
}

int main(void){
    init();
    display(board);
    display(eval_board);
    cout<<eval_board.size()<<endl;
    cout<<eval_board[0].size()<<endl;

    // from one row to one row
    // from left to right
    stack<array<int,2>> record_finish;
    stack<array<int,2>> respawn;


    for(int row=0;row<MAX_ROW;row++){
        for(int col=0;col<MAX_COL;col++){
            if(eval_board[row][col]==FILL_EMPTY){
                
                record_finish.push({row,col});
                // find one satisfies the condition of fill the sudoki
                if(!find_possible({row,col},eval_board[row][col]+1)){

                    respawn.push(record_finish.top());
                    record_finish.pop();
                    while (!respawn.empty())
                    {
                        // display(eval_board);
                        Site present_top=record_finish.top();
                        while(!find_possible(present_top,eval_board[present_top[0]][present_top[1]]+1)){
                            respawn.push(present_top);
                            record_finish.pop();
                            if(record_finish.empty()){
                                return -1;
                            }
                            eval_board[present_top[0]][present_top[1]]=FILL_EMPTY;
                            present_top=record_finish.top();
                        }

                        Site wait_respawn=respawn.top();
                        while(find_possible(wait_respawn,FILL_EMPTY+1)){
                            record_finish.push(wait_respawn);
                            
                            respawn.pop();
                            if(respawn.empty()){
                                break;
                            }
                            wait_respawn=respawn.top();
                        }
                        //eval_board[wait_respawn[0]][wait_respawn[1]]))
                    }
                    
                }


                cout<<"----------------new break---------------------"<<endl;
                print({row,col});
                cout<<eval_board[row][col]<<endl;
                cout<<"-------------------------------------"<<endl;



            }
        }
    }
    display(eval_board);
    return 0;
    
}
