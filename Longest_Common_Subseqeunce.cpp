#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lengthOfLIS(vector<int> &nums)
{
    if (nums.empty())
        return 0;

    // This vector will store the smallest tail for all increasing subsequences
    // of various lengths.
    vector<int> subsequence;

    for (int num : nums)
    {
        // Find the first element in subsequence which is not less than num
        auto it = lower_bound(subsequence.begin(), subsequence.end(), num);

        // If num is greater than any element in subsequence, append it
        if (it == subsequence.end())
        {
            subsequence.push_back(num);
        }
        else
        {
            // Replace the found element with num
            *it = num;
        }
    }

    // The size of subsequence is the length of the longest increasing subsequence.
    return subsequence.size();
}

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of Longest Increasing Subsequence: " << lengthOfLIS(nums) << endl;
    return 0;
}