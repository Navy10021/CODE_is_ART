// Right(Clockwise) Left(anti-clockwise) Rotate the given string(where d <= n)

/*
Left Rotate(string, d) 
    reverse(string, 0, d-1);    // reverse substring s[0 ... d-1]
    reverse(string, d, n-1);    // reverse substring s[d, ... n-1]
    reverse(string, 0, n-1);    // reverse whole string
*/

#include<bits/stdc++.h>
using namespace std;

void left_rotate(string &s, int d){
    reverse(s.begin(), s.begin()+d);
    reverse(s.begin()+d, s.end());
    reverse(s.begin(), s.end());
}

void right_rotate(string &s, int d){
    left_rotate(s, s.length() - d);
}


int main()
{
    string input = "SNU GSDS ";
    
    // left Rotate
    left_rotate(input, 3);
    cout << input << '\n';
    
    // right Rotate
    right_rotate(input, 3);
    cout << input << '\n';
}
