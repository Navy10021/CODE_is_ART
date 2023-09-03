#include <bits/stdc++.h>
using namespace std;
 
// Helper function to perform DFS
bool dfs(vector<int>& arr1, vector<int>& arr2, vector<bool>& visited,
         int index) {
    // Base case: All elements have been visited
    if (index == arr1.size()) {
        return true;
    }
 
    // Check if the current element in arr1 has a
   // corresponding element in arr2
    int num = arr1[index];
    for (int i = 0; i < arr2.size(); i++) {
        if (!visited[i] && arr2[i] == num) {
            visited[i] = true;
            if (dfs(arr1, arr2, visited, index + 1)) {
                return true;
            }
            visited[i] = false; // Backtrack
        }
    }
 
    return false;
}
 
// Returns true if arr1[] and arr2[] are permutations of each other
bool arePermutations(vector<int>& arr1, vector<int>& arr2) {
    int n = arr1.size();
    int m = arr2.size();
 
    // Arrays cannot be permutations of one another unless
   // they are of the same length
    if (n != m) {
        return false;
    }
 
    // Initialize a visited array to keep track of used elements
   // in arr2
    vector<bool> visited(m, false);
 
    // Perform DFS to check for permutations
    return dfs(arr1, arr2, visited, 0);
}
 
// Driver function to test above function
int main() {
    vector<int> arr1 = {2, 1, 3, 5, 4, 3, 2};
    vector<int> arr2 = {3, 2, 2, 4, 5, 3, 1};
 
    if (arePermutations(arr1, arr2)) {
        cout << "Arrays are permutations of each other" << endl;
    } else {
        cout << "Arrays are NOT permutations of each other" << endl;
    }
 
    return 0;
}
