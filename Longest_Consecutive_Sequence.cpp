#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> numSet(nums.begin(), nums.end());
    int longestStreak = 0;

    for (int num : nums)
    {
        // Only start a new sequence if num-1 is NOT in the set (ensures start of a sequence)
        if (numSet.find(num - 1) == numSet.end())
        {
            int currentNum = num;
            int currentStreak = 1;

            // Count consecutive numbers
            while (numSet.find(currentNum + 1) != numSet.end())
            {
                currentNum += 1;
                currentStreak += 1;
            }

            longestStreak = max(longestStreak, currentStreak);
        }
    }
    return longestStreak;
}

int main()
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Longest Consecutive Sequence: " << longestConsecutive(nums) << endl;
    return 0;
}
