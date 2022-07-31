#pragma once
using namespace std;
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
private:
	//ʹ��scope����¼������ÿ�����������μ�¼�������⵽�ڵ�����ֵ������ʱֻ��Ҫ�������һ����ֵ��
	unordered_map<string, vector<int>> scope;

public:
	int evaluate(string expression){
		int start = 0;
		return innerEvaluate(expression, start);
	}

	int innerEvaluate(const string& expression, int& start)
	{
		if (expression[start] != '(') //�Ǳ��ʽ������Ϊ���������
		{
			if (islower(expression[start])) //����
			{
				string var = parseVar(expression, start);
				return scope[var].back();
			}
			else //����
			{
				return parseInt(expression, start);
			}
		}
		int ret;
		start++; //�Ƴ�������
		if (expression[start] == 'l') //"let"���ʽ
		{
			start += 4; //�Ƴ�"let"
			vector<string> vars;
			while (true)
			{
				if (!islower(expression[start]))
				{
					ret = innerEvaluate(expression, start); //let���ʽ�����һ��expr���ʽ��ֵ
					break;
				}
				string var = parseVar(expression, start);
				if (expression[start] == ')')
				{
					ret = scope[var].back(); //let���ʽ�����һ��expr���ʽ��ֵ
					break;
				}
				vars.push_back(var);
				start++; //�Ƴ��ո�
				int e = innerEvaluate(expression, start);
				scope[var].push_back(e);
				start++; //�Ƴ��ո�
			}
			for (auto var : vars)
			{
				scope[var].pop_back(); //�����ǰ������ı���
			}
		}
		else if (expression[start] == 'a') //"add"���ʽ
		{
			start += 4;
			int e1 = innerEvaluate(expression, start);
			start++;
			int e2 = innerEvaluate(expression, start);
			ret = e1 + e2;
		}
		else //"mult"���ʽ
		{
			start += 5;
			int e1 = innerEvaluate(expression, start);
			start++;
			int e2 = innerEvaluate(expression, start);
			ret = e1 * e2;
		}
		start++; //�Ƴ�������
		return ret;
	}

	int parseInt(const string& expression, int& start) //��������
	{
		int n = expression.size();
		int ret = 0, sign = 1;
		if (expression[start] == '-')
		{
			sign = -1;
			start++;
		}
		while (start < n && isdigit(expression[start]))
		{
			ret = ret * 10 + (expression[start] - '0');
			start++;
		}
		return sign * ret;
	}

	string parseVar(const string& expression, int& start) //��������
	{
		int n = expression.size();
		string ret;
		while (start < n && expression[start] != ' ' && expression[start] != ')')
		{
			ret.push_back(expression[start]);
			start++;
		}
		return ret;
	}
};