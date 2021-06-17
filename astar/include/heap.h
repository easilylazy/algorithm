#ifndef _HEAP_H_
#define _HEAP_H_
# include<iostream>
# include<cmath>
# include<memory>
# include<vector>
# include"site.h"
using namespace std;
typedef Site DataType;
typedef pair<DataType,int> NodeType;


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
    int extract_min_value();
    NodeType extract_min();

    void add_min(NodeType n);
};



#endif
