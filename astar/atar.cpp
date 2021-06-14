#include <iostream>
#include <random>
#include "atar.h"

MapGraph::MapGraph(int size){
    map_size=size;
    map_size_min=0;
    map_size_max=size-1;
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
    upLeft=Site(0,0);
    downRight=Site(size-1,size-1);
    
}
void MapGraph::astar(){


    // first: push src 
    open.push_back(make_pair(src,0));

    Site current;
    int minCost;
    int minSite;
    while(!open.empty()){
        // find the smallest in the open
        minCost=open[0].second;
        minSite=0;
        
        for(int i=1;i<open.size();i++){
            auto item=open[i];
            if(item.second<minCost){
                minCost=item.second;
                current=item.first;
                minSite=i;
            }
        }
        open[minSite]=open[open.size()-1];
        open.pop_back();
        // visit current minCost
        // find its neighboor and update the cost
        Site updated;
        for(enum Direction d=Direction(DirectionMin+1);d<DirectionMax;d=Direction(d+1)){
            updated=current.chooseDirection(d);
            if(updated.inside(upLeft,downRight)){
                cout<<updated;
            }

        }


    }



    if(src==dst){
        cout<<"equal"<<endl;
    }else{
        cout<<"unequal"<<endl;

    }
}
