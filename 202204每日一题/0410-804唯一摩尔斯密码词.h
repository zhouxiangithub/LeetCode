#pragma once
using namespace std;
#include <vector>
#include <string>
#include <unordered_set>

const static string MORSE[] = {
    ".-","-...","-.-.","-..",".","..-.",
    "--.","....","..",".---","-.-",".-..",
    "--","-.","---",".--.","--.-",".-.",
    "...","-","..-","...-",".--","-..-",
    "-.--","--.."
};

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> seen;
        for (auto& word : words)
        {
            string code;
            for (auto& c : word)
            {
                code.append(MORSE[c - 'a']);
            }
            seen.emplace(code);
        }
        return seen.size();
    }
};