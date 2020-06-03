#pragma once
#include<iostream>
#include<string>
#include<stdlib.h>
#define ARRMAXSIZE 100000
struct bst
{
	int nodeData;
	struct bst* left;
	struct bst* right;
};
void generateRandArray(int* arr, int size);
bst* generateBst(bst* root, int* arr, int size);
bst* putNode(bst* root, int data);
void lastOrder(bst* root);
void lastOrderSave(bst* root, int*posArr, int&size);
bst* reconstructBst(bst* root, int* arr, int leftRange, int rightRange);
//���Ž⣺���ַ�
bst* reconstructBst2(bst* root, int* arr, int leftRange, int rightRange);

//�ж����������������Ƿ���ȫ��ͬ
bool sameBst(bst* root1, bst* root2);
void recycle(bst* root);
