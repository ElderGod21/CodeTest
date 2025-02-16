#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        
        // XOR all numbers in the array
        for(int num : nums) {
            result ^= num;
        }
        
        return result;
    }
};
