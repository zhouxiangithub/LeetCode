#pragma once
using namespace std;
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
private:
	//使用scope来记录作用域，每个变量都依次记录下它从外到内的所有值，查找时只需要查找最后一个数值。
	unordered_map<string, vector<int>> scope;

public:
	int evaluate(string expression){
		int start = 0;
		return innerEvaluate(expression, start);
	}

	int innerEvaluate(const string& expression, int& start)
	{
		if (expression[start] != '(') //非表达式，可能为整数或变量
		{
			if (islower(expression[start])) //变量
			{
				string var = parseVar(expression, start);
				return scope[var].back();
			}
			else //整数
			{
				return parseInt(expression, start);
			}
		}
		int ret;
		start++; //移除左括号
		if (expression[start] == 'l') //"let"表达式
		{
			start += 4; //移除"let"
			vector<string> vars;
			while (true)
			{
				if (!islower(expression[start]))
				{
					ret = innerEvaluate(expression, start); //let表达式的最后一个expr表达式的值
					break;
				}
				string var = parseVar(expression, start);
				if (expression[start] == ')')
				{
					ret = scope[var].back(); //let表达式的最后一个expr表达式的值
					break;
				}
				vars.push_back(var);
				start++; //移除空格
				int e = innerEvaluate(expression, start);
				scope[var].push_back(e);
				start++; //移除空格
			}
			for (auto var : vars)
			{
				scope[var].pop_back(); //清除当前作用域的变量
			}
		}
		else if (expression[start] == 'a') //"add"表达式
		{
			start += 4;
			int e1 = innerEvaluate(expression, start);
			start++;
			int e2 = innerEvaluate(expression, start);
			ret = e1 + e2;
		}
		else //"mult"表达式
		{
			start += 5;
			int e1 = innerEvaluate(expression, start);
			start++;
			int e2 = innerEvaluate(expression, start);
			ret = e1 * e2;
		}
		start++; //移除右括号
		return ret;
	}

	int parseInt(const string& expression, int& start) //解析整数
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

	string parseVar(const string& expression, int& start) //解析变量
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