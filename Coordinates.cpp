#include <vector>
using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        // Extract the first two points to calculate the reference slope
        int x1 = coordinates[0][0], y1 = coordinates[0][1];
        int x2 = coordinates[1][0], y2 = coordinates[1][1];
        int dx = x2 - x1, dy = y2 - y1;

        // Check slope consistency for all subsequent points
        for (int i = 2; i < coordinates.size(); i++) {
            int x = coordinates[i][0], y = coordinates[i][1];
            // Compare cross product to avoid division
            if ((y - y1) * dx != (x - x1) * dy) {
                return false; // Slope mismatch indicates not a straight line
            }
        }

        return true; // All points lie on the same straight line
    }
};
