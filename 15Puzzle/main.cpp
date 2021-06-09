# include<iostream>
# include<iomanip>
# include<vector>
# include"include/board.h"
using namespace std;



int main(void){
    Board demo(4);
    demo.print();
    demo.shuffle(29);
    // demo.possible_direction();
    // demo.exec_direction(Up);
    // demo.print();
    // demo.possible_direction();

    demo.BFS();
    demo.path();
    // demo.display();
    return 0;

}