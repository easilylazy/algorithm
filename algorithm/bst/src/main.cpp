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
	//�����������
	int size;
	int arr[ARRMAXSIZE];
	for (int step = 128;  step< ARRMAXSIZE; step*=4)
	{
		cout << "approximate size of array " << step << endl;
		int batch = 500;
		cout << "begin " << batch << " times test for solution 1:" << endl;
		start = clock();		//����ʼ��ʱ
		
		
		for (int i = 0; i < batch; i++)
		{
			//ȷ��������ɵ������С
			size = step;

			generateRandArray(arr, size);

			//������������
			bst* root = NULL;
			root = generateBst(root, arr, size);

			//��������������������������arr
			size = 0;
			lastOrderSave(root, arr, size);
			if (DEBUG)
			{
				cout << "origin:" << endl;
				for (int i = 0; i < size; i++)
					cout << arr[i];
				cout << endl;
			}

			//�ɺ����������arr�ؽ�����������
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
				//�Ƚ϶����Ƿ���ͬ������ͬ����ӡ��Ϣ
				if (!sameBst(root, reconstruct))
					cout << "************11111**not same*****111111**********" << endl;

				recycle(reconstruct);
			}
			//������Դ
			recycle(root);
			
		}

		endTime = clock();		//���������ʱ	
		double totalTime1 = (double)(endTime - start) / CLOCKS_PER_SEC;
		cout << "Complete! Total time:" << totalTime1 * 1000 << "ms" << endl;	//msΪ��λ

		cout << "begin " << batch << " times test for solution 2:" << endl;
		start = clock();		//����ʼ��ʱ
		for (int i = 0; i < batch; i++)
		{
			
			//ȷ��������ɵ������С
			size = step;
			generateRandArray(arr, size);

			//������������
			bst* root = NULL;
			root = generateBst(root, arr, size);

			//��������������������������arr
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
				//�����Ž�����������arr�ؽ�����������
				bst* reconstruct2 = NULL;
				reconstruct2 = reconstructBst2(reconstruct2, arr, 0, size - 1);
				if (DEBUG)
				{
					cout << "2:" << endl;
					lastOrder(reconstruct2);
					cout << endl;
				}
				//�Ƚ϶����Ƿ���ͬ������ͬ����ӡ��Ϣ
				if (!sameBst(root, reconstruct2)) 
					cout << "**********222222****not same*******222222******" << endl;
				

				recycle(reconstruct2);
			}

			recycle(root);
		}
		endTime = clock();		//���������ʱ	
		double totalTime2 = (double)(endTime - start) / CLOCKS_PER_SEC;
		cout << "Complete! Total time:" << totalTime2 * 1000 << "ms" << endl;	//msΪ��λ


		visualTime(1, totalTime1 * 1000, 10);
		visualTime(2, totalTime2 * 1000, 10);

		
	}

	

}
