#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
    int right = s.size() - 1;

    while (left < right) {
        // Move the left pointer to the next alphanumeric character
        while (left < right && !isalnum(s[left])) {
            left++;
        }

        // Move the right pointer to the previous alphanumeric character
        while (left < right && !isalnum(s[right])) {
            right--;
        }

        // Compare the characters in a case-insensitive manner
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }

        left++;
        right--;
    }

    return true;
        
    }
};