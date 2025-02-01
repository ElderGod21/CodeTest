#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    bool check(vector<int>& nums) {
         int n = nums.size();
    int count = 0; // Count of "rotational dips"

    for (int i = 0; i < n; i++) {
        // Check if the current element is greater than the next element
        if (nums[i] > nums[(i + 1) % n]) {
            count++;
        }
        // If there is more than one "rotational dip," it's not a valid rotated sorted array
        if (count > 1) {
            return false;
        }
    }

    return true;
    }

};