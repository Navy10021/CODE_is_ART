// Right(Clockwise) Left(anti-clockwise) Rotate the given string(where d <= n)

/*
Left Rotate(string, d) 
    temp = string + string;     // extended string 
    length = string.length;     
    return temp[d : length + d]

Right Rotate(string, d)
    Left Rotate(string, string.length - d)
*/

#include<bits/stdc++.h>
using namespace std;

string left_rotate(string s, int d){
    string tmp = s + s;
    int s_len = s.size();
    string left_s = tmp.substr(d, s_len);
    return left_s;
}

string right_rotate(string s, int d){
    return left_rotate(s, s.size()-d);
}


int main()
{
    string input = "SNU GSDS ";
    
    // left Rotate
    string output_1 = left_rotate(input, 3);
    cout << output_1 << '\n';
    
    // right Rotate
    string output_2 = right_rotate(input, 5);
    cout << output_2 << '\n';
}
