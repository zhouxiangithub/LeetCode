#pragma once
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    using EntityChar = pair<string, char>;
    
    vector<EntityChar> entityList;

    string entityParser(string text) {
        entityList = vector({
            (EntityChar){"&quot;",'"' },
            (EntityChar){"&apos;",'\'' },
            (EntityChar){"&amp;",'&' },
            (EntityChar){"&gt;",'>' },
            (EntityChar){"&lt;",'<' },
            (EntityChar){"&frasl;",'/' }
            });

        string res;
        for (int idx = 0; idx < text.size();)
        {
            bool flag = false;
            if (text[idx] == '&')
            {
                for (const auto& [str, cha] : entityList)
                {
                    if (text.substr(idx, str.size()) == str)
                    {
                        res.push_back(cha);
                        idx += str.size();
                        flag = true;
                        break;
                    }
                }
            }
            if (!flag)
            {
                res.push_back(text[idx++]);
            }
        }
        return res;
    }
};