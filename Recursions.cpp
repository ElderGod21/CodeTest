#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Factorial

int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * fact(n - 1);
}

// Printing in descending order to 1
void count(int n)
{
    if (n == 0)
        return;

    count(n - 1);

    cout << n << " ";
}

// Fibonacci Series

int fib(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    int ans = fib(n - 1) + fib(n - 2);

    return ans;
}

// Say digit
void digitNames(int n)
{
    if (n <= 0)
    {
        return;
    }
    string arr[10] = {"zero", "one", "two", "three", "four", "five",
                      "six", "seven", "eight", "nine"};
    int digit = n % 10;
    digitNames(n / 10);
    cout << arr[digit] << " ";
}

// If array is sorted or not
bool isSorted(int arr[], int size)
{
    if (size == 0 || size == 1)
        return true;

    if (arr[0] > arr[1])
        return false;

    else
    {
        bool ans = isSorted(arr + 1, size - 1);
        return ans;
    }
}

// sum of elements of array

int sumArray(int arr[], int size)
{
    if (size == 0)
        return 0;

    int sum = arr[0] + sumArray(arr + 1, size - 1);

    return sum;
}

// linear search using recursions

bool linearSearch(int arr[], int size, int target)
{
    if (size == 0)
        return 0;
    if (arr[0] == target)
        return 1;
    else
    {
        bool ans = linearSearch(arr + 1, size - 1, target);
        return ans;
    }
}

// Binary search using recursions

bool binarySearch(int arr[], int start, int end, int target)
{
    if (start > end)
        return false;

    int mid = start + (end - start) / 2;

    if (arr[mid] == target)
        return true;

    if (arr[mid] < target)
    {
        return binarySearch(arr, mid + 1, end, target);
    }
    else
    {
        return binarySearch(arr, start, mid - 1, target);
    }
}

// reversing a string using recursion

void reverseString(string &str, int i, int j)
{
    if (i > j)
        return;

    swap(str[i], str[j]);
    reverseString(str, i + 1, j - 1);
}

// power function (optimized)
int power(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;

    int ans = power(a, b / 2);

    if (b & 1)
        return a * ans * ans;
    else
        return ans * ans;
}

////// Merge Sort ******** /////

void merge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // copy values

    int mainArrayIndex = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }

    // merge 2 sorted arrays

    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while (index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }

    while (index2 < len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete[] first; // always remember to free up thr dynamic memory
    delete[] second;
}

void mergeSort(int *arr, int s, int e)
{
    if (s >= e)
        return;

    int mid = s + (e - s) / 2;
    // left part
    mergeSort(arr, s, mid);

    // right part
    mergeSort(arr, mid + 1, e);

    // merge
    merge(arr, s, e);
}

////********** QUICK SORT *************////

int partition(int arr[], int s, int e)
{
    int pivot = arr[s];
    int count = 0;

    for (int i = s + 1; i < e; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }

    int pivotIndex = s + count;
    swap(arr[s], arr[pivotIndex]);

    int i = s, j = e;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int s, int e){
    if(s>=e) return ;

    //partition
    int p = partition(arr, s, e);

    //Recursive
    quickSort(arr, s,  p-1);
    quickSort(arr, p+ 1, e);
}




//************Subsets**************

void solve(vector<int>nums, vector<int> output, int index, vector<vector<int>>& ans){
        if(index >= nums.size()){
            ans.push_back(output);
            return;
        }
        
        //exclude
        solve(nums, output, index +1, ans);
        
        //include 
        output.push_back(nums[index]);
        solve(nums, output, index +1, ans);
}
vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve(nums, output, index, ans);
        return ans;
}

int main()
{
    // int n = 6; 
    // int ans = fact(n);
    // count(n);
    // int ans = fib(n);
    // cout<<"Answer is: "<<ans ;

    // digitNames(n);
    // int arr[6] = {1, 3, 5, 6, 7, 9};
    // cout << isSorted(arr, n);

    // cout << sumArray(arr, n);

    // cout << linearSearch(arr, n, 0);

    // cout << binarySearch(arr, 0, 5, 2);

    // string str = "abcd";
    // reverseString(str, 0, 3);
    // cout << str;

    // cout << power(2, 0);

    // int arr[10] = {312, 3, 324, 5, 6, 7, 2, 76, 3, 556};
    // int n = 10;
    // mergeSort(arr, 0, n - 1);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i]<<" ";
    // }

    int arr[10] = {312, 3, 324, 5, 6, 7, 2, 76, 3, 556};
    int n = 10;
    quickSort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<<" ";
    }
}