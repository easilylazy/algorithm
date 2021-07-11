# include<iostream>
# include<iomanip>
# include<vector>
# include"include/board.h"
using namespace std;



int main(void){
    int steps=30;
    Board demo(3);
    demo.print();
    demo.shuffle(steps);

    board_type record=demo.board;
    demo.print();

    cout<<"differ:"<<demo.difference(demo.board)<<endl;

    cost_type (Board::*pfunc)(board_type); //声明一个和参数类型一样的函数指针  
    pfunc =& Board::difference; //指针指向要调用的函数  
    demo.better(pfunc);
    demo.path();
    
    Board demo2(3);
    demo2.modStart(record);
    demo2.BFS();

    demo2.path();
    // demo.display();
    return 0;

}