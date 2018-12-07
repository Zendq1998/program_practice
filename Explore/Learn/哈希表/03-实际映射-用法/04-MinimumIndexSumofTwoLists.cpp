/*
Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.

You need to help them find out their common interest with the least list index sum. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> map;
        int min = INT_MAX;
        vector<string> re;
        for (int i = 0; i < list1.size(); i += 1) {
            map[list1[i]] = i;
        }
        for (int i = 0; i < list2.size(); i += 1) {
            if (map.count(list2[i])) {
                if (map[list2[i]] + i == min) {
                    re.push_back(list2[i]);
                }
                else if (map[list2[i]] + i < min) {
                    re.clear();
                    re.push_back(list2[i]);
                    min = map[list2[i]] + i;
                }
            }
        }
        return re;
    }
};