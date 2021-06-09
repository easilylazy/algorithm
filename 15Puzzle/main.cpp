# include<iostream>
# include<iomanip>
# include<vector>
# include"include/board.h"
using namespace std;



int main(void){
    Board demo(3);
    demo.print();
    demo.shuffle(5);
    // demo.possible_direction();
    // demo.exec_direction(Up);
    // demo.print();
    // demo.possible_direction();

    demo.BFS();
    demo.path();
    // demo.display();
    return 0;



    vector<int> test;//(9);
    vector<int> test2;
    auto foo1=demo.board;
    auto foo2=demo.board;
    auto foo3=demo.board;
    foo3[0][0]=3;
    if(foo1==foo2){
        cout<<"fe1"<<endl;
    }
     if(foo1==foo3){
        cout<<"fe2"<<endl;
    }
    for(auto row:demo.board){
        copy(row.begin(),row.end(),back_inserter(test));
    }
    for(auto t:test){
        cout<<t<<endl;
    }
    if(test==test2){
        cout<<"e1"<<endl;
    }
    for(auto row:demo.board){
        copy(row.begin(),row.end(),back_inserter(test2));
    }
    if(test==test2){
        cout<<"e2"<<endl;
    }
}