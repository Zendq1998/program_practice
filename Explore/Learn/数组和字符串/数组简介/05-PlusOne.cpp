#include <iostream>
#include <vector> 
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result(digits);
        for (int i = result.size() - 1; i >= 0; i -= 1) {
            if (result[i] == 9) {
                result[i] = 0;
                if (i == 0) {
                    result.insert(result.begin(), 1);
                    return result;
                }
            }
            else {
                result[i] += 1;
                return result;
            }
        }
    }
};