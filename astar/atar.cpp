#include <iostream>
#include <random>
#include "atar.h"

MapGraph::MapGraph(int size){
    astar();
    map_size=size;
    graph=vector<vector<int>>(size);
    for(int i=0;i<size;i++){
        graph[i]=vector<int>(size);
        for(int j=0;j<size;j++){
            graph[i][j]=rand()%(cost_max-cost_min)+cost_min;
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    src=Site(0,0);
    dst=Site(size-1,size-1);
    astar();
}
void MapGraph::astar(){
    if(src==dst){
        cout<<"equal"<<endl;
    }else{
        cout<<"unequal"<<endl;

    }
}
