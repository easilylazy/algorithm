# include<iostream>
# include<iomanip>
# include<vector>
# include"include/board.h"
using namespace std;



int main(void){
    Board demo(3);
    demo.print();
    demo.possible_direction();
    return 0;
}