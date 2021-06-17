# include<iostream>
# include<cmath>
using namespace std;

class Heap{
private:
    int size=10;
    int *pArray;
public:
    Heap(int size=10);
    ~Heap();
    int parent(int i);
    int left_child(int i);
    int right_child(int i);
    int* children(int i);
    friend std::ostream &operator <<(std::ostream & os, const Heap &h);
    
};

std::ostream &operator <<(std::ostream & os, const Heap & h){
        for(int i=0;i<h.size;i++){
            os<<" "<<i<<" : "<<*(h.pArray+i)<<std::endl;
        }
        return os;
}   
Heap::Heap(int size){
    this->size=size;
    pArray = new int(size);
    for(int i=0;i<size;i++){
        *(pArray+i)=i;
    }
}
Heap::~Heap(){
    if(pArray){
        delete pArray;
        pArray=NULL;
    }
}

int Heap::parent(int i){
    return floor((i-1)/2);
}

int Heap::left_child(int i){
    return 2*i+1;
}

int Heap::right_child(int i){
    return 2*i+2;
}

class SortHeap : public Heap
{
private:
    bool MinRoot=true;
public:
    SortHeap(bool MinRoot=true);
    // ~SortHeap();
};

SortHeap::SortHeap(bool MinRoot)
{
}


