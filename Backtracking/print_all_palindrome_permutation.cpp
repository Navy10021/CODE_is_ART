#include <bits/stdc++.h>
using namespace std;

// 1.palindrome function : can make palindrome or not
bool is_palin(string str, int* freq){
    // Initializing frequency array with all zeros
    memset(freq, 0, 26*sizeof(int));
    int L = str.length();
    
    // update frequency according to given string
    for (int i=0; i<L; i++) freq[str[i]-'a']++;
    
    // count total letter with odd frequency
    int odd = 0;
    for (int i=0; i<26; i++){
        if (freq[i]%2 == 1) odd++;
    }
    
    // palindrome condition check : 홀수길이 + 홀수 freq 1개만 / 짝수 길이 + 홀수 freq x
    if ((L%2==1 && odd==1) || (L%2==0 && odd==0))
        return true;
    else
        return false;
}

// 2. string reverse 
string reverse(string str){
    string rev_str = str;
    reverse(rev_str.begin(), rev_str.end());
    return rev_str;
}

// 3. pring all possible palindrome
void print_all_palin(string str){
    int freq[26];
    
    // 3-1. check if letter can make palindrome or not
    if (!is_palin(str, freq))
        return;
    int L = str.length();
    
    // 3-2. half : contain half part of all palindromes
    string half = "";
    char odd_char;
    for (int i=0; i<26; i++){
        if (freq[i] % 2 == 1) 
            odd_char = i+'a';       // odd character
        
        half += string(freq[i] / 2, i+'a');  // ???
    }
    string palin;
    do{
        palin = half;
        if (L%2 == 1)
            palin += odd_char;
        palin += reverse(half);
            cout << palin << ' ';
    }
    while (next_permutation(half.begin(), half.end()));
    
}

int main(void){
    string str = "aabbccdda";
    print_all_palin(str);
    return 0;
}
