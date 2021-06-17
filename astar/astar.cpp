#include <iostream>
#include <random>
#include "include/astar.h"

MapGraph::MapGraph(int size){
    map_size=size;
    map_size_min=0;
    map_size_max=size-1;
    graph=vector<vector<int>>(size);
    for(int i=0;i<size;i++){
        graph[i]=vector<int>(size);
        for(int j=0;j<size;j++){
            graph[i][j]=rand()%(cost_max-cost_min)+cost_min;
            // cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    src=Site(0,0);
    dst=Site(size-1,size-1);
    upLeft=Site(0,0);
    downRight=Site(size-1,size-1);
    
}
void MapGraph::astar_heap(){
    // first: push src 
    OPEN.add_min(NodeType(src,0));
    // open.push_back(make_pair(src,0));
    closed[src]=make_pair(src,0);


    Site current;
    int minCost;
    int minSite;
    while(OPEN.getSize()>0){
        // find the smallest in the open
        NodeType current_min=OPEN.extract_min();
        minCost=current_min.second;
        current=current_min.first;
        OPEN.delete_min();
        // visit current minCost
        // find its neighboor and update the cost
        Site updated;
        int cost;
        for(enum Direction d=Direction(DirectionMin+1);d<DirectionMax;d=Direction(d+1)){
            updated=current.chooseDirection(d);
            if(updated>=upLeft&&updated<=downRight){
                cost=minCost+graph[updated.Row()][updated.Col()];
                auto old= closed.find(updated);

                if(old==closed.end()){
                    closed[updated]=make_pair(current,cost);
                    OPEN.add_min(make_pair(updated,cost));
                    if(verbose){
                        showCost();
                        if(updated==dst){
                            cout<< "achieve dst"<<endl;
                            cout<<"cost: "<<cost<<endl;
                        }
                    }
                    

                }
                else if(old->second.second>cost){
                    closed[updated]=make_pair(current,cost);
                    OPEN.add_min(make_pair(updated,cost));
                    if(verbose){
                        showCost();    
                        if(updated==dst){
                            cout<< "update dst"<<endl;
                            cout<<"cost: "<<cost<<endl;
                        }        
                    }        
                }
                
            }
        }
    }
    sortPath();
}
void MapGraph::astar(){
    // first: push src 
    open.push_back(make_pair(src,0));
    closed[src]=make_pair(src,0);


    Site current;
    int minCost;
    int minSite;
    while(!open.empty()){
        // find the smallest in the open
        current=open[0].first;
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
        int cost;
        for(enum Direction d=Direction(DirectionMin+1);d<DirectionMax;d=Direction(d+1)){
            updated=current.chooseDirection(d);
            if(updated>=upLeft&&updated<=downRight){
                cost=minCost+graph[updated.Row()][updated.Col()];
                auto old= closed.find(updated);

                if(old==closed.end()){
                    closed[updated]=make_pair(current,cost);
                    open.push_back(make_pair(updated,cost));
                    if(verbose){
                        showCost();
                        if(updated==dst){
                            cout<< "achieve dst"<<endl;
                            cout<<"cost: "<<cost<<endl;
                        }
                    }
                    

                }
                else if(old->second.second>cost){
                    closed[updated]=make_pair(current,cost);
                    open.push_back(make_pair(updated,cost));
                    if(verbose){
                        showCost();    
                        if(updated==dst){
                            cout<< "update dst"<<endl;
                            cout<<"cost: "<<cost<<endl;
                        }        
                    }        
                }
                
            }
        }
    }
    sortPath();
}
void MapGraph::sortPath(){
    int count=0;
    Site current=dst;
    path[current]=true;
    while(current!=src){
        if(++count>20){
            break;
        }
        current=closed[current].first;
        path[current]=true;
    }

}
void MapGraph::showCost(){
    cout<<"********COST**********"<<endl;
    int cost;
    for(int i=0;i<map_size;i++){
        for(int j=0;j<map_size;j++){
            auto res=closed.find(Site(i,j));
            if(res!=closed.end()){
                cout<<res->second.second <<" ";
            }else{
                cout<<"() ";
            }
        }
        cout<<endl;
    }
}
void MapGraph::showMap(){
    cout<<"********MAP**********"<<endl;
    for(int i=0;i<map_size;i++){
        for(int j=0;j<map_size;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}
void MapGraph::showPath(){
    showMap();
    cout<<"*******PATH**********"<<endl;
    for(int i=0;i<map_size;i++){
        for(int j=0;j<map_size;j++){
            if(path.find(Site(i,j))!=path.end()){
                cout<<graph[i][j]<<" ";
            }else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
}