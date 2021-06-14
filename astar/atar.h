#include <vector>
#include <map>
#include <stack>
#define DIRECTION_MAX 4
using namespace std;
enum Direction{DirectionMin,Left,Right,Up,Down,DirectionMax};
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
    Site chooseDirection(Direction direct){
        switch (direct)
        {
        case Up:
            return this->up();
        case Down:
            return this->down();
        case Left:
            return this->left();
        case Right:
            return this->right();
        default:
            break;
        }
        return *this;
    }
    Site arround(int rowBias=1,int colBias=1){
        return Site(x+rowBias,y+colBias);
    }
    Site left(int bias=1){
        return Site(x,y-1);
    }
    Site right(int bias=1){
        return Site(x,y+1);
    }
    Site up(int bias=1){
        return Site(x-bias,y);
    }
    Site down(int bias=1){
        return Site(x+1,y);
    }
    bool inside(Site upLeft,Site downRight){
        if(*this>=upLeft&&*this<=downRight){
            return true;
        }
        return false;
    }
    bool operator>=(const Site &site){
        if(this->x>=site.x&&this->y>=site.y){
            return true;
        }
        return false;
    }
    bool operator<=(const Site &site){
        if(this->x<=site.x&&this->y<=site.y){
            return true;
        }
        return false;
    }
    bool operator==(const Site &site){
        if(this->x==site.x&&this->y==site.y){
            return true;
        }
        return false;
    }
    friend ostream &operator <<(ostream & os, const Site & s){
        os<<"x: "<<s.x<<" y: "<<s.y<<endl;
        return os;
    }
};
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