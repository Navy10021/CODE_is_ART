#include<bits/stdc++.h>
using namespace std;

// insert characters(*) in a string at a certain position

string add_char(string str, vector<int>& posi){
    // Iterate through the vector positions
    int k = 0;
    for (int i=0; i < posi.size(); i++){
        // Insert a char
        str.insert(posi[i] + k++, "*");
    }
    return str;
}

int main()
{
    string input = "SNU GSDS";
    vector<int> position = {0,4};
    string output = add_char(input, position);
    cout << output << '\n';
    
    return 0;
}
