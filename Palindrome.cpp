#include <iostream>
#include <climits> // For INT_MAX and INT_MIN
using namespace std;

bool isPalindrome(int x) {
    // Negative numbers and numbers ending with 0 (except 0 itself) are not palindromes
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int reversedNumber = 0;
    int originalNumber = x;

    // Reverse the integer with overflow check
    while (x > 0) {
        int digit = x % 10;
        // Check for overflow before updating reversedNumber
        if (reversedNumber > (INT_MAX - digit) / 10) {
            return false; // Overflow would occur, hence not a palindrome
        }
        reversedNumber = reversedNumber * 10 + digit;
        x /= 10;
    }

    // Check if the original number is equal to the reversed number
    return originalNumber == reversedNumber;
}

int main() {
    int num;
    cout << "Enter an integer: ";
    cin >> num;

    if (isPalindrome(num)) {
        cout << num << " is a palindrome." << endl;
    } else {
        cout << num << " is not a palindrome." << endl;
    }
    return 0;
}
