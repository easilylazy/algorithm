#include<iostream>
#include<ctime>
#include "include/astar.h"
using namespace std;

int main(void){
    MapGraph randomMap(9);
    time_t time_s=clock();
    randomMap.astar();
    cout<<"it cost " << (double )(clock() - time_s) <<" ms"<<endl;
    randomMap.showCost();
    randomMap.showPath();
    return 0;

}