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
    
    demo.simple();
    demo.path();

    // return 0;
    // demo.possible_direction();
    // demo.exec_direction(Up);
    // demo.print();
    // demo.possible_direction();
    Board demo2(3);
    demo2.modStart(record);
    demo2.BFS();

    demo2.path();
    // demo.display();
    return 0;

}