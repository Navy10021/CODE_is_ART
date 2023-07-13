// Rearranged to form a Palindrome == Check if any anagram of string is palindrome or not.
#include <bits/stdc++.h>
using namespace std;


bool is_rearrange_palindrome(string str){
    // 1. Create a count arr of alphabet size (256) and initialize all values as 0;
    int count[256] = {0};
    // 2. Traverse the given string and count;
    for (int i = 0; i < str.length(); i++)
        count[str[i]]++;
    
    // 3. Traverse the count array and if count array has more than odd value -> false
    int odd = 0;    // odd count 
    for (int i = 0; i < 256; i++){
        if (count[i] & 1)   // count숫자가 홀수 = 1, 짝수 = 0;
            odd++;
        if (odd > 1)
            return false;
    }
    // return true if odd count is 0 or 1;
    return true;
}


int main()
{
    string str = "CCABBA"; 

    cout << is_rearrange_palindrome(str);
    
}
