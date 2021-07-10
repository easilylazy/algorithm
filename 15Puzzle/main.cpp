# include<iostream>
# include<iomanip>
# include<vector>
# include"include/board.h"
using namespace std;



int main(void){
    Board demo(3);
    demo.print();
    demo.shuffle(5);
    demo.print();

    cout<<"differ:"<<demo.difference(demo.board)<<endl;
    
    demo.simple();
    return 0;
    // demo.possible_direction();
    // demo.exec_direction(Up);
    // demo.print();
    // demo.possible_direction();

    demo.BFS();
    demo.path();
    // demo.display();
    return 0;

}