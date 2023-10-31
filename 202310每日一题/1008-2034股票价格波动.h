#pragma once
using namespace std;
#include <unordered_map>
#include <set>
#include <queue>

class StockPrice {
private:
    int maxTimestamp;
    unordered_map<int, int> timePriceMap;
    multiset<int> prices;

public:
    StockPrice() {
        this->maxTimestamp = 0;
    }

    void update(int timestamp, int price) {
        maxTimestamp = max(maxTimestamp, timestamp);
        int prePrice = timePriceMap.count(timestamp) ? timePriceMap[timestamp] : 0;
        timePriceMap[timestamp] = price;
        if (prePrice > 0)
        {
            auto it = prices.find(prePrice);
            if (it != prices.end())
            {
                prices.erase(it);
            }
        }
        prices.emplace(price);
    }

    int current() {
        return timePriceMap[maxTimestamp];
    }

    int maximum() {
        return *prices.rbegin();
    }

    int minimum() {
        return *prices.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */

typedef pair<int, int> pii;

class StockPrice {
private:
    int maxTimestamp;
    unordered_map<int, int> timePriceMap;
    priority_queue<pii, vector<pii>, less<pii>> pqMax;
    priority_queue<pii, vector<pii>, greater<pii>> pqMin;

public:
    StockPrice() {
        this->maxTimestamp = 0;
    }

    void update(int timestamp, int price) {
        maxTimestamp = max(maxTimestamp, timestamp);
        timePriceMap[timestamp] = price;
        pqMax.emplace(price, timestamp);
        pqMin.emplace(price, timestamp);
    }

    int current() {
        return timePriceMap[maxTimestamp];
    }

    int maximum() {
        while (true)
        {
            int price = pqMax.top().first, timestamp = pqMax.top().second;
            if (timePriceMap[timestamp] == price)
            {
                return price;
            }
            pqMax.pop();
        }
    }

    int minimum() {
        while (true)
        {
            int price = pqMin.top().first, timestamp = pqMin.top().second;
            if (timePriceMap[timestamp] == price)
            {
                return price;
            }
            pqMin.pop();
        }
    }
};