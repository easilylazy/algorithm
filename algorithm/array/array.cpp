#include"array.h"
//�����������Ϊlen�ַ�����ASCII�뷶Χleft��right
string generateArr(int len, int left, int right)
{
	if (left > right)
		return "";
	string str;// = "I lsfjo st";
	str.resize(len+1);

	for (int i = 0; i < len ; i++)
	{
		str[i] = left + rand() % (right - left);
		//cout<<str[i] << endl;
	}
	if (DEBUG)
	{
		cout << str << endl;
		cout << str.length() << endl;
	}
	
	return str;
}

//��ӡĳ������ΪsubLen�������ִ�
void findSubstr(string str, int subLen)
{
	cout << str.length() << endl;
	cout << subLen << endl;
	cout << str.length() - subLen << endl;
	if (str.length() < subLen)
		return;
	for (int i = 0; i < str.length()-subLen; i++)
	{
		//��ӡ��i��ʼ������ΪsubLen���Ӵ�
		cout << str.substr(i, subLen) << endl;
	}

}

//�Ƚ���aim������ͬ�ĵ������Ӵ��Ƿ��������ɷ�һ�£����У�����ƫ���������򷵻�-1
int findAim(string str, string aim)
{
	//cout << str.length() - aim.length() << endl;
	if (str.length() < aim.length())
		return -1;
	
	//���飬ͳ���ַ���Χ�ڵ��ַ����ָ���
	
	string substr;
	bool findAim;

	for (int i = 0; i < str.length() - aim.length(); i++)
	{
		int count[255] = {0};
		for (int i = 0; i < aim.length(); i++)
		{
			count[aim[i]]++;
		}
		if (DEBUG)
		{
			//��ӡ��i��ʼ������ΪsubLen���Ӵ�
			cout << i << ":\t" << str.substr(i, aim.length()) << endl;
		}
		
		substr = str.substr(i, aim.length());
		findAim = true;
		for (int i = 0; i < aim.length(); i++)
		{
			if (--count[substr[i]] < 0)
				findAim = false;				
		}
		if (findAim == true)
			return i;
	}
	return -1;
}

//�Ƚ���aim������ͬ�ĵ������Ӵ��Ƿ��������ɷ�һ�£����У�����ƫ���������򷵻�-1
//��2�����Ž⣬ͨ�������ڡ�
int findAim2(string str, string aim)
{
	//cout << str.length() - aim.length() << endl;
	if (str.length() < aim.length())
		return -1;

	//��ʼΪaim�ĸ��ַ�ֵ
	int count[255] = { 0 };
	int* pcnt = count + 97;
	for (int i = 0; i < aim.length(); i++)
		count[aim[i]]++;
	
	//��¼������aim�Ľ��׹�ϵ
	//��ʼֵ���ַ��ܳ���
	int owe = aim.length();

	//��һ������
	for (int i = 0; i < aim.length(); i++)
	{
		//���������ǻ�����Ҫ�еģ���ô�൱�ڡ�������̼����owe--
		if (count[str[i]]-- > 0)
			owe--;
		//����������֮ǰ���಻����Ҫ�ģ���ô�൱�ڡ��������󡱣�owe++
		else
			owe++;
	}
	if (owe == 0)
		return 0;

	//�ƶ������ڡ���ÿ���ƶ�����ȥһ���ַ�������һ���ַ��������ƶ�str.length() - aim.length()��
	//�Ƴ����ַ��ǵ�i�����������ַ��ǵ�i+aim.length()��
	for (int i = 0; i <= str.length() - aim.length(); i++)
	{
		//�ַ�
		int removed = str[i], added = str[i + aim.length()];
		//�ж�
		//�����Ƴ�����֮ǰ���಻�����ܵģ���ô�൱�ڡ���ʱֹ�𡱣�owe--
		if (count[removed]++ < 0)
			owe--;
		//�����Ƴ����ǻ�����Ҫ�еģ���ô�൱�ڡ���©ƫ����ҹ�ꡱ��owe++
		else
			owe++;

		//���������ǻ�����Ҫ�еģ���ô�൱�ڡ�������̼����owe--
		if (count[added]-- > 0)
			owe--;
		//����������֮ǰ���಻�����ܵģ���ô���������������һ�£�owe++
		else
			owe++;

		//ȫ�������������ƽ���ƶ���i�δ��ڣ�λ�ڵ�i+1��
		if (owe == 0)
			return i + 1;
	}
	return -1;
}