#pragma once
using namespace std;
#include <string>
#include <unordered_set>

/*
    �κγ���Ϊ2���߸����Ļ����ַ���������һ������Ϊ2����3�Ļ����ַ���
    ���ֻҪһ���ַ����е��κ��ַ���������ǰ�����ַ���ͬ����
*/
class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        for (int i = s.length() - 1; i >= 0; i--) {
            unordered_set<char> setChar;
            for (int j = 1; j <= 2; j++) { //ǰ����
                if (i - j >= 0) {
                    setChar.insert(s[i - j]);
                }
            }
            for (int j = 1; j <= 3; j++) {
                if (s[i] - 'a' + 1 + j <= k && setChar.find(s[i] + j) == setChar.end()) { //�ҵ���һ���ı��idx
                    return generate(s, i, j);
                }
            }
        }
        return "";
    }

    string generate(string s, int idx, int offset) {
        s[idx] += offset;
        for (int i = idx + 1; i < s.length(); i++) {
            unordered_set<char> setChar;
            for (int j = 1; j <= 2; j++) {
                if (i - j >= 0) {
                    setChar.insert(s[i - j]);
                }
            }
            for (int j = 0; j <= 2; j++) {
                if (setChar.find('a' + j) == setChar.end()) {
                    s[i] = 'a' + j;
                    break;
                }
            }
        }
        return s;
    }
};