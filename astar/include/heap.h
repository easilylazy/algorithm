# include<iostream>
# include<cmath>
# include<memory>
using namespace std;

class Heap{
private:
    int size=10;
    int *pArray;
    // unique_ptr<int> pTest;
public:
    int root_index=0;
    Heap(int size=10);
    Heap(int arr[],int size);
    virtual ~Heap();
    int getSize();
    int* node(int i);
    int parent_index(int i);
    int* parent(int i);
    bool parent(int i,int change);
    int left_child_index(int i);
    int* left_child(int i);
    int right_child_index(int i);
    int* right_child(int i);
    int* children(int i);
    friend std::ostream &operator <<(std::ostream & os, const Heap &h);
    
};

std::ostream &operator <<(std::ostream & os, const Heap & h){
        for(int i=0;i<h.size;i++){
            os<<" "<<i;
        }
        cout<<endl;
        for(int i=0;i<h.size;i++){
            os<<" "<<*(h.pArray+i);
        }
        cout<<endl;

        int thresh=0;
        for(int i=0;i<h.size;i++){
            for(int i=0;i<thresh+8-thresh*thresh;i++){
            cout<<" ";

            }
            os<<" "<<*(h.pArray+i);
            if(int(log2(i+2))>thresh){
                cout<<endl;
                thresh++;
            }
        }
        return os;
}   
Heap::Heap(int arr[],int size){
    this->size=size;
    pArray = new int(size);
    for(int i=0;i<size;i++){
        *(pArray+i)=arr[i];
    }    
}
Heap::Heap(int size){
    this->size=size;
    pArray = new int(size);
    for(int i=0;i<size;i++){
        *(pArray+i)=i;
    }    
}
Heap::~Heap(){
    cout<<" destuction of Heap()"<<endl;
    if(pArray){
        delete []pArray;
        pArray=NULL;
    }
}
int Heap::getSize(){
    return size;
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
bool Heap::parent(int i,int change){
    *parent(i)=change;
    return true;
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
    SortHeap(int arr[],int size,bool MinRoot=true);
    // ~SortHeap();
    void heapify();
};

SortHeap::SortHeap(bool MinRoot)
{
}
    
SortHeap::SortHeap(int arr[],int size,bool MinRoot):Heap(arr,size){
}
void SortHeap::heapify(){
    for(int i=0;i<getSize();i++){
        int p_i=parent_index(i);
        if(parent_index(i)==root_index){
            continue;
        }
        while(*node(i)>*node(p_i)){
            int temp=*node(i);
            *node(i)=*node(parent_index(i));
            *node(parent_index(i))=temp;
            if(p_i==root_index){
                break;
            }
            i=p_i;
            p_i=parent_index(i);
        }
    } 
}


