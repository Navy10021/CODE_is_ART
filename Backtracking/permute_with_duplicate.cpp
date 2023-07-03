#include <bits/stdc++.h>
using namespace std;

// permutations of a given string with duplicates


// 1. find the index of the smallest character which is greater than 'first'
int find_ceil(string str, char first, int l, int h){
    // initialization
    int ceil_idx = l; 
    // find the smallest character greater than first
    for (int i = l + 1; i <= h; i++){
        if (str[i] > first && str[i] < str[ceil_idx])
            ceil_idx = i;
    }
    return ceil_idx;
}

void sorted_permute(string str){
    // get size
    int size = str.length();
    // sorting
    sort(str.begin(), str.end());
    // print permutation one by one 
    bool is_finished = false;
    while (!is_finished){
        cout << str << '\n';
        // Find the character which is smaller than its next character.
        int i;
        for (i = size-2; i >= 0; --i){
            if (str[i] < str[i + 1]) 
                break;
        }
        // If there is no such character, all are sorted in decreasing order.
        if (i==-1)
            is_finished = true;
        else{
            // Find ceil of a character
            int second = find_ceil(str, str[i], i+1, size-1);
            // Swap first and second characters
            swap(str[i], str[second]);
            // Sort the string on right of first char
            sort(str.begin() + i + 1, str.end());
        }
        
    }
}

int main(void){
    string input = "ACBC";
    sorted_permute(input);
    return 0;

}
