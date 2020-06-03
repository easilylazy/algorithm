#include"../include/bst.h"
using namespace std;


void generateRandArray(int*arr,int size)
{	
	
	
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % ARRMAXSIZE;
		//cout << arr[i];
	}
	//cout << endl;
	
}
void recycle(bst* root)
{
	
	if (root->left == NULL && root->right == NULL)
	{
		delete root;
		return;
	}
	if(root->left!=NULL)
		recycle(root->left);
	if(root->right!=NULL)
		recycle(root->right);
	delete root;
	return;
}
bst* generateBst(bst*root,int* arr, int size)
{
	
	for (int i = 0; i < size; i++)
	{
		root = putNode(root, arr[i]);
	}
	return root;
	//lastOrder(root);
	
}
bst* putNode(bst* node, int data)
{
	if (node == NULL)
	{
		node = new(bst);
		node->nodeData = data;
		node->left = NULL;
		node->right = NULL;
		return node;
	}
	if (data < node->nodeData)
		node->left = putNode(node->left, data);
	if (data > node->nodeData)
		node->right = putNode(node->right, data);
	return node;
}
void lastOrder(bst* root)
{
	if (root == NULL)
		return;
	lastOrder(root->left);
	lastOrder(root->right);
	cout << root->nodeData;
}
void lastOrderSave(bst* root,int*posArr,int&size)
{
	if (root == NULL)
		return;
	lastOrderSave(root->left,posArr,size);
	lastOrderSave(root->right,posArr,size);
	//cout << root->nodeData;
	*(posArr+size)=(root->nodeData);
	size++;
}

bst* reconstructBst(bst* root, int* arr, int leftRange, int rightRange)
{
	if (leftRange > rightRange)
		return NULL;
	root = new bst;
	root->nodeData = arr[rightRange];
	//最末一个节点
	if (rightRange == leftRange )
	{
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	int limit;
	//得到分界处的角标limit
	for (limit = rightRange-1; limit>-1; limit--)
	{ 
		if (arr[limit] < arr[rightRange])		
			break;		
	}
	//建左子树和右子树
	root->left = reconstructBst(root->left, arr, leftRange, limit);
	root->right = reconstructBst(root->right, arr, limit+1, rightRange-1);
	return root;
}

//最优解：二分法得分界处角标

bst* reconstructBst2(bst* root, int* arr, int leftRange, int rightRange)
{
	if (leftRange > rightRange)
		return NULL;
	root = new bst;
	root->nodeData = arr[rightRange];
	//最末一个节点
	if (rightRange == leftRange)
	{
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	//二分法找到分界处的角标mid
	int left = leftRange, right = rightRange - 1;
	int mid = left + ((right - left) >> 1); //二分
	for (; right>=left; )
	{
		if (arr[mid] > arr[rightRange])
		{
			right = mid - 1;
			mid = left + ((mid - left) >> 1);//落在前半部分
		}
		else
		{
			left = mid+1;
			mid = right - ((right - mid) >> 1);//落在后半部分
		}
	}
	int limit;
	if (arr[mid] < arr[rightRange])
		limit = mid;
	else
		limit = mid - 1;
	//建左子树和右子树
	root->left = reconstructBst(root->left, arr, leftRange, limit);
	root->right = reconstructBst(root->right, arr, limit + 1, rightRange - 1);
	
	return root;
}



bool sameBst(bst* root1, bst* root2)
{
	bool result;

	if (root1 == NULL || root2 == NULL)
	{
		if (root1 == NULL && root2 == NULL)
			return true;
		else
			return false;
	}
	result=sameBst(root1->left, root2->left)&&sameBst(root1->right, root2->right)&& root1->nodeData == root2->nodeData;
	
	return result;
}
