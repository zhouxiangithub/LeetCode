#pragma once
using namespace std;
#include <string>
#include <vector>

/*
    ��fi��ʾ��siΪ���һ���ַ��������е���Ŀ
    (1)�����������ֻ��si��һ���ַ�����ô��һ�ַ�����
    (2)����������������������ַ���״̬ת�Ʒ��̣������ڶ����ַ�������s0,s1,...,s[i-1]�е�ĳһ��������
    fi = f0 + f1 + ... + f[i-1], Ϊ�˱����ظ����㣬����ÿһ���ַ�������ֻ��Ҫ�ҵ������һ�γ��ֵ�λ�ã�
    ������λ��i֮ǰ��������Ӧ��fֵ�ۼӽ�fi���ɡ�

*/
class Solution {
public:
    int distinctSubseqII(string s) {
        vector<int> last(26, -1);

        int n = s.length();
        vector<int> f(n, 1); //��ʼ��ÿ��fi��Ϊ1
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (last[j] != -1)
                {
                    f[i] = (f[i] + f[last[j]]) % mod;
                }
            }
            last[s[i] - 'a'] = i;
        }

        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            if (last[i] != -1)
            {
                ans = (ans + f[last[i]]) % mod;
            }
        }
        return ans;
    }
private:
    static constexpr int mod = 1000000007;
};