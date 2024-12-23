#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // If the input vector is empty, return an empty string
        if (strs.empty()) return "";

        // Start with the first string as the reference prefix
        string prefix = strs[0];

        // Compare the prefix with each string in the array
        for (size_t i = 1; i < strs.size(); ++i) {
            // Adjust the prefix until it matches the start of the current string
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.size() - 1); // Remove the last character
                if (prefix.empty()) return ""; // If prefix becomes empty, no common prefix exists
            }
        }

        return prefix;
    }
};

// Example usage
int main() {
    Solution solution;
    vector<string> strs = {"flower", "flow", "flight"};

    string result = solution.longestCommonPrefix(strs);
    cout << "Longest Common Prefix: " << result << endl;

    return 0;
}
