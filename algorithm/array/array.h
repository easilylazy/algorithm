#pragma once
#include<string>
#include<stdlib.h>	
#include<iostream>
#define DEBUG false
using namespace std;
string generateArr(int len, int left, int right);
void findSubstr(string str, int subLen);
//比较与aim长度相同的的所有子串是否含有与它成分一致，若有，返回偏移量，否则返回-1
int findAim(string str, string aim);
//比较与aim长度相同的的所有子串是否含有与它成分一致，若有，返回偏移量，否则返回-1
//法2：最优解，通过“窗口”
int findAim2(string str, string aim);
