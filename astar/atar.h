#include <vector>
#include <map>
#include <stack>
#include "site.h"

#define DIRECTION_MAX 4
using namespace std;
enum Direction{DirectionMin,Left,Right,Up,Down,DirectionMax};

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
    // map<Site,int> open;
    vector<pair<Site,int>> open;
    // stack<Site,


public:
    MapGraph(int size);
    void astar();
};