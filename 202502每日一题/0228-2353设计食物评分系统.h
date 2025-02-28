#pragma once
using namespace std;
#include <vector>
#include <string>
#include <unordered_map>
#include <set>

class FoodRatings {
private:
    int n;
    unordered_map<string, pair<int, string>> foodMap; // food-(rating,cuisine)
    unordered_map<string, set<pair<int, string>>> cuisineMap; // cuisine-{(-rating,food),...}

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        n = foods.size();
        for (int i = 0; i < n; i++) {
            string food = foods[i], cuisine = cuisines[i];
            int rating = ratings[i];
            foodMap[food] = { rating,cuisine };
            cuisineMap[cuisine].emplace(-rating, food);
        }
    }

    void changeRating(string food, int newRating) {
        auto& [rating, cuisine] = foodMap[food];
        auto& ratingFood = cuisineMap[cuisine];
        ratingFood.erase({ -rating,food });
        ratingFood.emplace(-newRating, food);
        rating = newRating;
    }

    string highestRated(string cuisine) {
        return cuisineMap[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */