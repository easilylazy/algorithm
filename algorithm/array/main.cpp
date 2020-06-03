#include"array.h"

int main(void)
{
	int site, site2;
	string aim = "bc";
	for (int i = 5; i < 1000; i++)
	{
		
		//findSubstr(generateArr(i, 97, 123),5);
		string geneArr = generateArr(i, 97, 123);
		
		site = findAim(geneArr, aim);
		if (DEBUG)
		{
			if (site >= 0)
				cout << "***way1******find at " << site << endl;
		}
		

		site2 = findAim2(geneArr, aim);
		if (DEBUG)
		{
			if (site >= 0)
				cout << "***way2******find at " << site << endl;

		}
		if (site != site2)
		{
			cout << "wrong" << endl;
		}
		
	}
	
	return 0;
}