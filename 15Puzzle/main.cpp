# include<iostream>
# include<iomanip>
# include<vector>
# include"include/board.h"
using namespace std;



int main(int argc, char* argv[]){
    int steps=20;
    int size=3;
    if(argc>0){
        size=atoi(argv[1]);
        if(argc>1){
            steps=atoi(argv[2]);
        }
    }else{
        cout<<"USAGE ./board.exe [size] [steps]"<<endl;
    }
    Board demo(size);

    demo.print("TARGET");
    demo.shuffle(steps);
    cout<<"after shuffle "<<steps<<" steps"<<endl;
    board_type record=demo.board;
    demo.print("START");

    // cout<<"differ:"<<demo.steps(demo.board)<<endl;
    // cout<<"differ:"<<demo.reverse(demo.board)<<endl;

    cost_type (Board::*pfunc)(board_type); //声明一个和参数类型一样的函数指针  
    demo.modStart(record);
    // pfunc =& Board::difference;
    // demo.better(pfunc);
    demo.better(& Board::difference);
    demo.modStart(record);

    // pfunc =& Board::steps;
    // demo.better(pfunc);
    demo.better(& Board::steps);
    demo.modStart(record);

    pfunc =& Board::reverse; 
    demo.better(& Board::reverse);
    demo.modStart(record);

    pfunc =& Board::difference_reverse; 
    demo.better(& Board::difference_reverse);

    // demo.path();
    demo.modStart(record);
    
    demo.BFS();

    // demo2.path();
    // demo.display();
    return 0;

}