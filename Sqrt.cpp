class Solution {
public:
    int mySqrt(int x) {
    if (x == 0 || x == 1) return x; // Base cases

    int start = 0, end = x, ans = 0;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        // Check if mid is a perfect square
        if (mid <= x / mid) {
            ans = mid;  // Update ans
            start = mid + 1;  // Narrow down to the upper half
        } else {
            end = mid - 1;  // Narrow down to the lower half
        }
    }
    return ans;
    }
    
};