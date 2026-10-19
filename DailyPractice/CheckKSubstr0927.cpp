#include<unordered_set>
#include<iostream>
#include<cmath>
using namespace std;

class Solution {
public:
    unordered_set<string> substrs;
    bool hasAllCodes(string s, int k) {
        for (int i = 0; i <= (int)s.size() - k; ++i) {
            substrs.insert(s.substr(i, k));
        }
        return (long long)substrs.size() == (long long)(pow(2, k));
    }
};