#include"../include/bst.h"
#include<ctime>
using namespace std;
#define DEBUG false//true//true
#define SOLUTION1 true//false//true
#define SOLUTION2 true//false

clock_t start, endTime;
void visualTime(int way, double value,double scale)
{
	cout << way << ": " ;
	for (int i = 0; i < value/scale; i++)
	{
		cout << "*";
	}
	cout << endl;
}

int main(void)
{
	//生成随机数组
	int size;
	int arr[ARRMAXSIZE];
	for (int step = 128;  step< ARRMAXSIZE; step*=4)
	{
		cout << "approximate size of array " << step << endl;
		int batch = 500;
		cout << "begin " << batch << " times test for solution 1:" << endl;
		start = clock();		//程序开始计时
		
		
		for (int i = 0; i < batch; i++)
		{
			//确定随机生成的数组大小
			size = step;

			generateRandArray(arr, size);

			//建搜索二叉树
			bst* root = NULL;
			root = generateBst(root, arr, size);

			//后序遍历二叉树结果保存至数组arr
			size = 0;
			lastOrderSave(root, arr, size);
			if (DEBUG)
			{
				cout << "origin:" << endl;
				for (int i = 0; i < size; i++)
					cout << arr[i];
				cout << endl;
			}

			//由后序遍历数组arr重建搜索二叉树
			if (SOLUTION1)
			{
				bst* reconstruct = NULL;
				reconstruct = reconstructBst(reconstruct, arr, 0, size - 1);
				if (DEBUG)
				{
					cout << "1:" << endl;
					lastOrder(reconstruct);
					cout << endl;
				}
				//比较二者是否相同，若不同，打印消息
				if (!sameBst(root, reconstruct))
					cout << "************11111**not same*****111111**********" << endl;

				recycle(reconstruct);
			}
			//回收资源
			recycle(root);
			
		}

		endTime = clock();		//程序结束用时	
		double totalTime1 = (double)(endTime - start) / CLOCKS_PER_SEC;
		cout << "Complete! Total time:" << totalTime1 * 1000 << "ms" << endl;	//ms为单位

		cout << "begin " << batch << " times test for solution 2:" << endl;
		start = clock();		//程序开始计时
		for (int i = 0; i < batch; i++)
		{
			
			//确定随机生成的数组大小
			size = step;
			generateRandArray(arr, size);

			//建搜索二叉树
			bst* root = NULL;
			root = generateBst(root, arr, size);

			//后序遍历二叉树结果保存至数组arr
			size = 0;
			lastOrderSave(root, arr, size);
			if (DEBUG)
			{
				cout << "origin:" << endl;
				for (int i = 0; i < size; i++)
					cout << arr[i];
				cout << endl;
			}


			if (SOLUTION2)
			{
				//由最优解后序遍历数组arr重建搜索二叉树
				bst* reconstruct2 = NULL;
				reconstruct2 = reconstructBst2(reconstruct2, arr, 0, size - 1);
				if (DEBUG)
				{
					cout << "2:" << endl;
					lastOrder(reconstruct2);
					cout << endl;
				}
				//比较二者是否相同，若不同，打印消息
				if (!sameBst(root, reconstruct2)) 
					cout << "**********222222****not same*******222222******" << endl;
				

				recycle(reconstruct2);
			}

			recycle(root);
		}
		endTime = clock();		//程序结束用时	
		double totalTime2 = (double)(endTime - start) / CLOCKS_PER_SEC;
		cout << "Complete! Total time:" << totalTime2 * 1000 << "ms" << endl;	//ms为单位


		visualTime(1, totalTime1 * 1000, 10);
		visualTime(2, totalTime2 * 1000, 10);

		
	}

	

}
