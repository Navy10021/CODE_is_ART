#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype> // for std::tolower or std::toupper

using namespace std;

int countWords(const string& str){
    int wordCount = 0;
    bool inWord = false;

    for (char c : str){
        if(isspace(c)){
            inWord = false;
        }
        else{
            if (!inWord){
                wordCount++;
            }
        }
    }
    return wordCount;
}

unordered_map<string, int> HashCount(const string& str){
    unordered_map<string, int> Hash;
    string currWord;

    for (char c : str){
        // If the character is an alphanumeric character, add it to the current word.
        if (isalpha(c) || isdigit(c)){
            //currWord += tolower(c);
            currWord += c;
        }
        // If the character is not alphanumeric and the current word is not empty, increment its count.
        else if (!currWord.empty()){
            Hash[currWord]++;
            currWord.clear();
        }
    }
    // Increment count for the last word if the string dosen't end non-alphanumeric characters.
    if (!currWord.empty()){
        Hash[currWord]++;
    }
    return Hash;
}

int main(void){
    /*
    // 1. Declaration and Initialization.
    string str1;                    // Create an empty string
    //str1 = "Lee";
    string str2 = "Hello, ";        // Initalization with C-style
    string str3(5, 'A');            // Initalization with repetition of a char
    string str4 = str2 + "world.";  // string concatenation

    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;
    cout << str4 << endl;

    // 2. Accessing Element.
    char ch = str4[0];
    char firstChar = str4.front();
    char lastChar = str4.back();

    cout << ch << endl;
    cout << firstChar << endl;
    cout << lastChar << endl;

    // 3. Modifiy the string
    str2 += "world";
    cout << str2 << endl;
    str2.append("!!!");     // Appending another string
    cout << str2 << endl;
    str2.push_back('@');    // Appending a Single char
    cout << str2 << endl;

    // 4. string length
    int len = str2.length();    // Return the length of the string
    int size = str2.size();     // Return the number of characters in strings
    bool isEmpty = str2.empty();

    cout << len << endl;
    cout << size << endl;
    cout << isEmpty << endl;

    // 5. String Comparsion.
    str1 = str2;
    if (str1 == str2){              // Compare
        cout << "Is Equal." << endl;
    }
    str1.push_back('.');
    if (str2.compare(str1) == 0){   // Compare
        cout << "Is Equal." << endl;
    }
    else{
        cout << "Is NOT equal." << endl;
    }

    // 6. Substring
    string substr = str2.substr(7, 5);  // From 7-th index until 5-number of characters.
    cout << substr << endl;
    */
    // 7. Word Count
    string input;
    cout << "Enter a string : ";
    getline(cin, input);
    // Count Word
    unordered_map<string, int> res = HashCount(input);
    // Print
    for (const auto& pair : res){
        cout << "Word : " << pair.first << ", Count : " << pair.second << endl;
    }
    return 0;

}
