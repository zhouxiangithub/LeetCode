#pragma once
using namespace std;
#include <string>
#include <unordered_map>

class Solution {
private:
    unordered_map<int, string> dataBase;
    int id;

public:
    Solution() {
        id = 0;
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        id++;
        dataBase[id] = longUrl;
        return longUrl + "/" + to_string(id);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int index = shortUrl.rfind('/') + 1;
        int key = stoi(shortUrl.substr(index, int(shortUrl.size()) - index));
        return dataBase[key];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));