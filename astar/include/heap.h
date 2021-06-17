# include<iostream>
# include<cmath>
# include<memory>
# include<vector>
using namespace std;
typedef int DataType;
typedef pair<int,DataType> NodeType;
class Heap{
private:
    // int *pArray;
    //*pArray;
    // unique_ptr<int> pTest;
public:
    int size=10;
    int root_index=0;
    vector<NodeType> arr; 

    Heap(int size=0);
    Heap(int arr[],int size);
    // virtual ~Heap();
    void swap(int i,int j);
    int getSize();
    int node_value(int i)const;
    int parent_index(int i);
    int left_child_index(int i);
    int right_child_index(int i);
    void pop_back();
    friend std::ostream &operator <<(std::ostream & os, const Heap &h);
    
};
void Heap::swap(int i,int j){
    NodeType temp;
    temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
void Heap::pop_back(){

}
std::ostream &operator <<(std::ostream & os, const Heap & h){
        for(int i=0;i<h.size;i++){
            os<<" "<<i;
        }
        cout<<endl;
        for(int i=0;i<h.size;i++){
            os<<" "<<h.node_value(i);
        }
        cout<<endl;

        int thresh=0;
        for(int i=0;i<h.size;i++){
            for(int i=0;i<thresh+8-thresh*thresh;i++){
            cout<<" ";

            }
            os<<" "<<(h.node_value(i));
            if(int(log2(i+2))>thresh){
                cout<<endl;
                thresh++;
            }
        }
        return os;
}   
Heap::Heap(int arr[],int size){
    this->size=size;
    this->arr = vector<NodeType>(size);
    for(int i=0;i<size;i++){
        this->arr[i].first=arr[i];
    }    
}
Heap::Heap(int size){
    this->size=size;
    this->arr = vector<NodeType>(size);
    for(int i=0;i<size;i++){
        this->arr[i].first=i;
    }    
}
// Heap::~Heap(){
//     cout<<" destuction of Heap()"<<endl;
//     if(pArray){
//         delete []pArray;
//         pArray=NULL;
//     }
// }
int Heap::getSize(){
    return size;
}
int Heap::node_value(int i)const{
    if(i<0||i>=size){
        return -1;
    }
    return (arr[i].first);
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
    void siftUp_min(int i);
    void siftDown(int i,int end);
    void siftDown_min(int i,int end);
    void delete_min();
    int extract_min();
    void add_min(NodeType n);
};

SortHeap::SortHeap(bool MinRoot)
{
    
}
void SortHeap::add_min(NodeType n){
    arr.push_back(n);
    size++;
    siftUp_min(size-1);
}
void SortHeap::delete_min(){
    this->swap(root_index,size-1);
    size--;
    siftDown_min(root_index,size);
    arr.pop_back();
}
int SortHeap::extract_min(){
    return node_value(root_index);
}
    
SortHeap::SortHeap(int arr[],int size,bool MinRoot):Heap(arr,size){
}
void SortHeap::heapSort(){
    heapify(getSize());

    int end=getSize();

    while(end>root_index){
        // swap first and last
        this->swap(root_index,end-1);
        siftDown(0,end-1);
        cout<<*this<<endl;
        end--;
    }
}
void SortHeap::heapify(int length){
    for(int i=0;i<length;i++){
        siftUp(i);
    } 
}
void SortHeap::siftUp(int i){
    if(i==root_index){
        return;
    }
    int p_i=parent_index(i);
    while(node_value(i)>node_value(p_i)){
        this->swap(i,p_i);
        if(p_i==root_index){
            break;
        }
        i=p_i;
        p_i=parent_index(i);
    }
}
void SortHeap::siftUp_min(int i){
    if(i==root_index){
        return;
    }
    int p_i=parent_index(i);
    while(node_value(i)<node_value(p_i)){
        this->swap(i,p_i);
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
    if(node_value(i)<node_value(l_i)){
        toSwap=l_i;
    }
    int r_i=right_child_index(i);
    if(r_i<end){
        if(toSwap==l_i&&node_value(l_i)<node_value(r_i)){
            toSwap=r_i;
        }else if(toSwap==0&&node_value(i)<node_value(r_i)){
            toSwap=r_i;
        }
    }
    if(toSwap!=0){
        this->swap(i,toSwap);
        siftDown(toSwap,end);
    }
}

void SortHeap::siftDown_min(int i,int end){
    int l_i=left_child_index(i);
    if(l_i>=end){
        return;
    }
    int toSwap=0;
    if(node_value(i)>node_value(l_i)){
        toSwap=l_i;
    }
    int r_i=right_child_index(i);
    if(r_i<end){
        if(toSwap==l_i&&node_value(l_i)>node_value(r_i)){
            toSwap=r_i;
        }else if(toSwap==0&&node_value(i)>node_value(r_i)){
            toSwap=r_i;
        }
    }
    if(toSwap!=0){
        this->swap(i,toSwap);
        siftDown_min(toSwap,end);
    }
}


