#pragma once
#include<string>
#include<stdlib.h>	
#include<iostream>
#define DEBUG false
using namespace std;
string generateArr(int len, int left, int right);
void findSubstr(string str, int subLen);
//�Ƚ���aim������ͬ�ĵ������Ӵ��Ƿ��������ɷ�һ�£����У�����ƫ���������򷵻�-1
int findAim(string str, string aim);
//�Ƚ���aim������ͬ�ĵ������Ӵ��Ƿ��������ɷ�һ�£����У�����ƫ���������򷵻�-1
//��2�����Ž⣬ͨ�������ڡ�
int findAim2(string str, string aim);
