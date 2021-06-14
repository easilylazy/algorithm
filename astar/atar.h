#include <vector>
using namespace std;
class Site{
private:
    int x;
    int y;
public:
    Site(){
        x=0;
        y=0;
    }
    Site(int row,int col){
        x=row;
        y=col;
    }
    bool operator==(const Site &site){
        if(this->x==site.x&&this->y==site.y){
            return true;
        }
        return false;
    }
};
class MapGraph{
private:
    int cost_min=0;
    int cost_max=10;
    int map_size;
    vector<vector<int>> graph;
    Site src,dst;

public:
    MapGraph(int size);
    void astar();
};