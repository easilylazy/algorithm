#include <iostream>
#include "atar.h"

MapGraph::MapGraph(int size){
    graph=vector<vector<int>>(size);
    for(int i=0;i<size;i++){
        graph[i]=vector<int>(size);
        for(int j=0;j<size;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}
