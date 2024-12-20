class Solution {
public:
    bool isPalindrome(int x) {
        if( x < 0 || (x % 10 == 0 && x != 0)){
            return false;
        }
        int reversedNumber = 0;
        int originalNumber = x;

        while (x > 0) {
          int digit = x % 10;
          reversedNumber = reversedNumber * 10 + digit;
          x/= 10;}

    return originalNumber == reversedNumber;  
}
};