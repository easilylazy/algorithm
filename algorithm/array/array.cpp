#include"array.h"
//生成随机长度为len字符串，ASCII码范围left到right
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

//打印某个长度为subLen的所有字串
void findSubstr(string str, int subLen)
{
	cout << str.length() << endl;
	cout << subLen << endl;
	cout << str.length() - subLen << endl;
	if (str.length() < subLen)
		return;
	for (int i = 0; i < str.length()-subLen; i++)
	{
		//打印从i开始，长度为subLen的子串
		cout << str.substr(i, subLen) << endl;
	}

}

//比较与aim长度相同的的所有子串是否含有与它成分一致，若有，返回偏移量，否则返回-1
int findAim(string str, string aim)
{
	//cout << str.length() - aim.length() << endl;
	if (str.length() < aim.length())
		return -1;
	
	//数组，统计字符范围内的字符出现个数
	
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
			//打印从i开始，长度为subLen的子串
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

//比较与aim长度相同的的所有子串是否含有与它成分一致，若有，返回偏移量，否则返回-1
//法2：最优解，通过“窗口”
int findAim2(string str, string aim)
{
	//cout << str.length() - aim.length() << endl;
	if (str.length() < aim.length())
		return -1;

	//初始为aim的各字符值
	int count[255] = { 0 };
	int* pcnt = count + 97;
	for (int i = 0; i < aim.length(); i++)
		count[aim[i]]++;
	
	//记录窗口与aim的交易关系
	//初始值是字符总长度
	int owe = aim.length();

	//第一个窗口
	for (int i = 0; i < aim.length(); i++)
	{
		//若新增的是还在需要中的，那么相当于“火中送碳”，owe--
		if (count[str[i]]-- > 0)
			owe--;
		//若新增的是之前冗余不被需要的，那么相当于“供非所求”，owe++
		else
			owe++;
	}
	if (owe == 0)
		return 0;

	//移动“窗口”，每次移动：拿去一个字符，新增一个字符，共可移动str.length() - aim.length()次
	//移除的字符是第i个，新增的字符是第i+aim.length()个
	for (int i = 0; i <= str.length() - aim.length(); i++)
	{
		//字符
		int removed = str[i], added = str[i + aim.length()];
		//判断
		//若被移除的是之前冗余不被接受的，那么相当于“及时止损”，owe--
		if (count[removed]++ < 0)
			owe--;
		//若被移除的是还在需要中的，那么相当于“屋漏偏逢连夜雨”，owe++
		else
			owe++;

		//若新增的是还在需要中的，那么相当于“火中送碳”，owe--
		if (count[added]-- > 0)
			owe--;
		//若新增的是之前冗余不被接受的，那么与最初发生的事情一致，owe++
		else
			owe++;

		//全部抵消，世界和平，移动了i次窗口，位于第i+1处
		if (owe == 0)
			return i + 1;
	}
	return -1;
}