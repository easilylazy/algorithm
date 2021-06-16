#include <vector>
#include <map>
#include <stack>
#include "site.h"

#define DIRECTION_MAX 4
using namespace std;
class MapGraph{
private:
    int cost_min=0;
    int cost_max=10;
    int map_size;
    int map_size_min;
    int map_size_max;
    vector<vector<int>> graph;
    Site src,dst;
    Site upLeft,downRight;
    // vector<Site> closed;
    // vector<Site> open;

    map<Site,pair<Site,int>> closed;// smallest cost
    vector<pair<Site,int>> open;
    map<Site,bool> path;

    // stack<Site,


public:
    MapGraph(int size);
    void astar();
    void sortPath();
    void showMap();
    void showPath();
    void showCost();
};