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
    closed[src]=make_pair(src,0);


    Site current;
    int minCost;
    int minSite;
    while(!open.empty()){
        // find the smallest in the open
        minCost=open[0].second;
        minSite=0;
        current=open[0].first;

        for(int i=1;i<open.size();i++){
            auto item=open[i];
            if(item.second<minCost){
                minCost=item.second;
                current=item.first;
                minSite=i;
            }
        }
        if(current==Site(1,0)){
            cout<<"here"<<endl;
        }
        open[minSite]=open[open.size()-1];
        open.pop_back();
        // visit current minCost
        // find its neighboor and update the cost
        Site updated;
        int cost;
        // map<Site,pair<Site,int>>::iterator old;
        for(enum Direction d=Direction(DirectionMin+1);d<DirectionMax;d=Direction(d+1)){
            updated=current.chooseDirection(d);
            if(updated==Site(1,2)){
                cout<<"here"<<endl;
            }
            if(updated>=upLeft&&updated<=downRight){
                cost=minCost+graph[updated.Row()][updated.Col()];

                // cout<<updated;
                if(updated==dst){
                    cout<< "success"<<endl;
                    cout<<"cost: "<<minCost+graph[updated.Row()][updated.Col()]<<endl;
                    // closed[updated]=make_pair(current,cost);
                    showCost();

                    // break;
                }
                auto old= closed.find(updated);

                if(old==closed.end()){
                    closed[updated]=make_pair(current,cost);
                    open.push_back(make_pair(updated,cost));
                    showCost();

                }
                else if(old->second.second>cost){
                    closed[updated]=make_pair(current,cost);
                    open.push_back(make_pair(updated,cost));
                    showCost();

                // cout<<updated;
                // cout<<"cost: "<<cost<<endl;
                    
                    
                }
                
            }
        }


    }
    cout<<"*****************"<<endl;
    int count=0;
    current=dst;
    path[current]=true;
    while(current!=src){
        if(++count>20){
            break;
        }
        cout<<"from:"<<endl;
        cout<<closed[current].first;
        cout<<"cost:"<<endl;
        cout<<closed[current].second<<endl;
        current=closed[current].first;
        path[current]=true;
    }
}
void MapGraph::showCost(){
    cout<<"\n"<<endl;
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
    cout<<"\n"<<endl;
    for(int i=0;i<map_size;i++){
        for(int j=0;j<map_size;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}
void MapGraph::showPath(){
    showMap();
    cout<<"\n"<<endl;
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