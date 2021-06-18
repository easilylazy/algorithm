#ifndef _HEAP_H_
#define _HEAP_H_
# include<iostream>
# include<cmath>
# include<memory>
# include<vector>
using namespace std;

// 改动一：增加函数模板的声明——而这又需要先声明类模板
template<typename T1> class Heap;
template <typename T1>
std::ostream &operator<<(std::ostream & os, const Heap<T1> &h);

template<typename T1>
class Heap{
public:
    int size=0;
    int root_index=0;
    vector<T1> content;

    Heap(int size=0);
    Heap(T1 content[],int size=0);
    // virtual ~Heap();
    void swap(int i,int j);
    int getSize();
    int node_value(int i)const;
    int parent_index(int i);
    int left_child_index(int i);
    int right_child_index(int i);
    void pop_back();
    friend std::ostream &operator<<<>(std::ostream & os, const Heap<T1> &h);
    
};
template<typename T1>
class SortHeap : public Heap<T1>
{
private:
    bool MinRoot=true;
public:
    using Heap<T1>::content;  
    using Heap<T1>::size;  
    using Heap<T1>::root_index;  
    using Heap<T1>::node_value;  
    using Heap<T1>::getSize;  
    using Heap<T1>::parent_index;  
    using Heap<T1>::left_child_index;  
    using Heap<T1>::right_child_index;  

    SortHeap(bool MinRoot=true);
    SortHeap(int content[],int size,bool MinRoot=true);
    // ~SortHeap();
    void heapify(int length);
    void heapSort();
    void siftUp(int i);
    void siftUp_min(int i);
    void siftDown(int i,int end);
    void siftDown_min(int i,int end);
    void delete_min();
    int extract_min_value();
    // NodeType extract_min();
    T1 extract_min();
    void add_min(T1 n);
};

template<typename T1>
void Heap<T1>::swap(int i,int j){
    
    T1 temp;
    temp=content[i];
    content[i]=content[j];
    content[j]=temp;
}
template<typename T1>
void Heap<T1>::pop_back(){

}
template<typename T1>
std::ostream &operator<<(std::ostream & os, const Heap<T1> & h){
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
template<typename T1> 
Heap<T1>::Heap(T1 content[],int size){
    this->size=size;
    this->content = vector<T1>(size);
    for(int i=0;i<size;i++){
        this->content[i].second=content[i];
    }    
}
template<typename T1> 
Heap<T1>::Heap(int size){
    this->size=size;
    this->content = vector<T1>(size);
    for(int i=0;i<size;i++){
        this->content[i].second=i;
    }    
}
template<typename T1>
int Heap<T1>::getSize(){
    return size;
}
template<typename T1>
int Heap<T1>::node_value(int i)const{
    if(i<0||i>=size){
        return -1;
    }
    return (content[i].second);
}

template<typename T1>
int Heap<T1>::parent_index(int i){
    return floor((i-1)/2);
}
template<typename T1>
int Heap<T1>::left_child_index(int i){
    int lc=2*i+1;
    return lc;
}
template<typename T1>
int Heap<T1>::right_child_index(int i){
    int rc=2*i+2;
    return rc;
}
template<typename T1>
SortHeap<T1>::SortHeap(bool MinRoot)
{
    
}
template<typename T1>
void SortHeap<T1>::add_min(T1 n){
    content.push_back(n);
    size++;
    siftUp_min(size-1);
}
template<typename T1>
void SortHeap<T1>::delete_min(){
    this->swap(root_index,size-1);
    size--;
    siftDown_min(root_index,size);
    content.pop_back();
}
template<typename T1>
T1 SortHeap<T1>::extract_min(){
    return content[root_index];
}
template<typename T1>
int SortHeap<T1>::extract_min_value(){
    return node_value(root_index);
}
template<typename T1>    
SortHeap<T1>::SortHeap(int content[],int size,bool MinRoot):Heap<T1>(content,size){
}
template<typename T1>
void SortHeap<T1>::heapSort(){
    heapify(getSize());

    int end=getSize();

    while(end>root_index){
        // swap second and last
        this->swap(root_index,end-1);
        siftDown(0,end-1);
        cout<<*this<<endl;
        end--;
    }
}
template<typename T1>
void SortHeap<T1>::heapify(int length){
    for(int i=0;i<length;i++){
        siftUp(i);
    } 
}
template<typename T1>
void SortHeap<T1>::siftUp(int i){
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
template<typename T1>
void SortHeap<T1>::siftUp_min(int i){
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
template<typename T1>
void SortHeap<T1>::siftDown(int i,int end){
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
template<typename T1>
void SortHeap<T1>::siftDown_min(int i,int end){
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


#endif
