// Baekjoon14888.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <string>
using namespace std;
void Backtracking(queue<int> _values, int plusamount, int minusamount, int multiamount, int divamount, int value);
int minvalue = 1000000001, maxvalue = -1000000001;
int plusamount, minusamount, multiamount, divamount;
int main()
{
	int length;
	queue<int> values;
	cin >> length;
	for (int i = 0; i < length; i++)
	{
		int value;
		cin >> value;
		values.push(value);
	}
	cin >> plusamount >> minusamount >> multiamount >> divamount;
	int temp = values.front();
	values.pop();
	Backtracking(values, plusamount, minusamount, multiamount, divamount, temp);
	cout << maxvalue<<"\n" << minvalue;
}
void Backtracking(queue<int> _values, int plusamount, int minusamount, int multiamount, int divamount, int value)
{
	if (_values.empty())
	{
		if (value > maxvalue)
		{
			maxvalue = value;
		}
		if (value < minvalue)
		{
			minvalue = value;
		}
	}
	else
	{
		int temp = _values.front();
		_values.pop();
		if (plusamount > 0)
		{
			Backtracking(_values,plusamount-1,minusamount,multiamount,divamount,value+temp);
		}
		if (minusamount > 0)
		{
			Backtracking(_values,plusamount,minusamount - 1,multiamount,divamount,value-temp);
		}
		if (multiamount > 0)
		{
			Backtracking(_values,plusamount,minusamount,multiamount - 1,divamount,value*temp);
		}
		if (divamount > 0)
		{
			Backtracking(_values,plusamount,minusamount,multiamount,divamount - 1,value/temp);
		}
	}
}
