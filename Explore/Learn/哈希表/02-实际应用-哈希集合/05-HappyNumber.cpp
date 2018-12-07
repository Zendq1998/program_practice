/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
*/

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
private:
    unordered_set<int> set;
public:
    bool isHappy(int n) {
        if (n == 1) return true;
        if (set.count(n)) return false;
        set.insert(n);
        int newNum = 0, temp = n;
        while(temp > 0) {
            newNum += pow((temp%10), 2);
            temp /= 10;
        }
        return isHappy(newNum);
    }
};