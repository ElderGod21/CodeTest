#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        unordered_map<int, int> freq;  // To count frequencies of each element
        unordered_set<int> occurrences;  // To store unique occurrence counts

        // Count frequencies of each element in `arr`
        for (int num : arr) {
            freq[num]++;
        }

        // Check for uniqueness of frequencies
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            if (occurrences.find(it->second) != occurrences.end()) {
                return false;  // Duplicate frequency found
            }
            occurrences.insert(it->second);
        }

        return true;  // All frequencies are unique
    }
};
