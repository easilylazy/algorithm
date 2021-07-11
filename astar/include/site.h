#include<iostream>
enum Direction{DirectionMin,Left,Right,Up,Down,DirectionMax};

class Site{
private:
    int x;
    int y;
public:
    int Row(){
        return x;
    }
    int Col(){
        return y;
    }
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
    bool inside(const Site &upLeft,const Site &downRight){
        if(*this>=upLeft&&*this<=downRight){
            return true;
        }
        return false;
    }
    // for map::find()
	bool operator() (const Site &left ,const Site& right) const{
        if(left.x!=right.x){
            return left.x<right.x;
        }
        return left.y<right.y;

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
    bool operator!=(const Site &site){
        if(this->x==site.x&&this->y==site.y){
            return false;
        }
        return true;
    }
    friend bool operator < (const Site &left, const Site &right){
        if(left.x!=right.x){
            return left.x<right.x;
        }
        return left.y<right.y;
    }
    friend std::ostream &operator <<(std::ostream & os, const Site & s){
        os<<"x: "<<s.x<<" y: "<<s.y<<std::endl;
        return os;
    }
};