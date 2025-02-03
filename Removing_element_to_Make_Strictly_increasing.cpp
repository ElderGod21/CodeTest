#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:

    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        int count = 0; // To count the number of decreasing pairs
        int index = -1; // To store the index of the first decreasing pair

        // Identify the first pair where nums[i] >= nums[i+1]
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] >= nums[i + 1]) {
                count++;
                index = i;
            }
            // If more than one such pair exists, return false
            if (count > 1) {
                return false;
            }
        }

        // If no decreasing pair exists, the array is already strictly increasing
        if (count == 0) {
            return true;
        }

        // Check if removing nums[index] or nums[index+1] works
        // Case 1: Remove nums[index]
        if (index == 0 || nums[index - 1] < nums[index + 1]) {
            return true;
        }
        // Case 2: Remove nums[index + 1]
        if (index + 1 == n - 1 || nums[index] < nums[index + 2]) {
            return true;
        }

        return false;
    }
};