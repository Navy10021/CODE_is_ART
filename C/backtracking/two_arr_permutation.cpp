#include <bits/stdc++.h>
using namespace std;
 
// Returns true if arr1[] and arr2[] are permutations of each other
bool arePermutations(int arr1[], int arr2[], int n, int m)
{
    // Arrays cannot be permutations of one another unless they are
    // of the same length
    if (n != m)
    {
        return false;
    }
 
    // Sort both arrays
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
 
    // Compare each element of both arrays
    for (int i = 0; i < n; i++)
    {
        if (arr1[i] != arr2[i])
        {
            return false;
        }
    }
 
    return true;
}
 
// Driver function to test above function
int main()
{
    int arr1[] = {2, 1, 3, 5, 4, 3, 2};
    int arr2[] = {3, 2, 2, 4, 5, 3, 1};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
 
    if (arePermutations(arr1, arr2, n, m))
    {
        cout << "Arrays are permutations of each other" << endl;
    }
    else
    {
        cout << "Arrays are NOT permutations of each other" << endl;
    }
 
    return 0;
}
