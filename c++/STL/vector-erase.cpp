#include <algorithm> // for std::remove
#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    vector<int> vec;
    for (int i = 0; i < 10; i++){
        vec.push_back(i);
    }
    
    for (auto& i : vec){
        cout << i << " ";
    }
    cout << endl;
    
    // find the target element
    int target = 4;
    auto it = find(vec.begin(), vec.end(), target);
    
    // Check if element was found 
    if (it != vec.end()){
        vec.erase(it);
    }
    
    /*
    Remove all elements
    vec.erase(remove(vec.begin(), vec.end(), target), vec.end());
    *.
    for (auto& i : vec){
        cout << i << " ";
    }
    
    return 0;
}