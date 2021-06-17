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
    int* node(int i);
    int parent_index(int i);
    int* parent(int i);
    int left_child_index(int i);
    int* left_child(int i);
    int right_child_index(int i);
    int* right_child(int i);
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
int* Heap::node(int i){
    if(i<=0||i>=size){
        return pArray;
    }
    return pArray+i;
}
int* Heap::parent(int i){
    return pArray+parent_index(i);
}
int* Heap::right_child(int i){
    return pArray+right_child_index(i);
}
int* Heap::left_child(int i){
    return pArray+left_child_index(i);
}
int Heap::parent_index(int i){
    if(i<=0||i>=size){
        return 0;
    }
    return floor((i-1)/2);
}

int Heap::left_child_index(int i){
    int lc=2*i+1;
    if(lc<=0||lc>=size){
        return 0;
    }
    return lc;
}

int Heap::right_child_index(int i){
    int rc=2*i+2;
    if(rc<=0||rc>=size){
        return 0;
    }
    return rc;
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


