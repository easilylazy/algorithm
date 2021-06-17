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
    return floor((i-1)/2);
}

int Heap::left_child_index(int i){
    int lc=2*i+1;
    return lc;
}

int Heap::right_child_index(int i){
    int rc=2*i+2;
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
    void heapify(int length);
    void heapSort();
    void siftUp(int i);
    void siftDown(int i,int end);
};

SortHeap::SortHeap(bool MinRoot)
{
}
    
SortHeap::SortHeap(int arr[],int size,bool MinRoot):Heap(arr,size){
}
void SortHeap::heapSort(){
    heapify(getSize());

    int end=getSize();

    while(end>root_index){
        cout<<end<<endl;
        cout<<*this<<endl;
    // swap first and last
        swap(*node(root_index),*node(end-1));
        cout<<"swap"<<endl;

        cout<<*this<<endl;

        siftDown(0,end-1);
        end--;
    }



}
void SortHeap::heapify(int length){
    for(int i=0;i<length;i++){
        siftUp(i);
    } 
}
void SortHeap::siftUp(int i){
    int p_i=parent_index(i);
    if(p_i==root_index){
        return;
    }
    while(*node(i)>*node(p_i)){
        swap(*node(i),*node(p_i));
        if(p_i==root_index){
            break;
        }
        i=p_i;
        p_i=parent_index(i);
    }
}
void SortHeap::siftDown(int i,int end){
    int l_i=left_child_index(i);
    if(l_i>=end){
        return;
    }
    int toSwap=0;
    if(*node(i)<*node(l_i)){
        toSwap=l_i;
    }
    int r_i=right_child_index(i);
    if(r_i<end){
        if(toSwap==l_i&&*node(l_i)<*node(r_i)){
            toSwap=r_i;
        }else if(toSwap==0&&*node(i)<*node(r_i)){
            toSwap=r_i;
        }
    }
    if(toSwap!=0){
        swap(*node(i),*node(toSwap));
        siftDown(toSwap,end);
    }
}


