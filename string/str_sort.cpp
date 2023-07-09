#include<bits/stdc++.h>
using namespace std;

// sort : merge sort 

void sort_str(string &str){
    sort(str.begin(), str.end());
}

int main()
{
    string input = "SNU GSDS";
    sort_str(input);
    cout << input << '\n';
    
    return 0;
}
