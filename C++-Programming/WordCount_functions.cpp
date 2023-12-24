#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>           // for std::tolower or std::toupper

using namespace std;

unordered_map<char, int> getCharCount(const string& str) {
    unordered_map<char, int> CharCount;

    for (char c : str) {
        // Increment count for each character
        CharCount[c]++;
    }

    return CharCount;
}

void getCharCOunt2(const string& str){
    int CharHash[52] = {0};
    /*
    for (int i = 0; str[i] != '\0'; i++){
        char curr = str[i];

        if ('A' <= curr && curr <= 'Z'){
            CharHash[curr - 'A']++;
        }
        else if ('a' <= curr && curr <= 'z'){
            CharHash[curr - 'a' + 26]++;
        }
    }
    */
    for (char curr : str){
        if (isalpha(curr)){
            if (isupper(curr)){
                CharHash[curr - 'A']++;
            }
            else{
                CharHash[curr - 'a' + 26]++;
            }
        }
    }
    // Print the count
    for (int i = 0; i < 26; i++) {
        cout << "'" << static_cast<char>('A' + i) << "'  || Count : " << CharHash[i] << endl;
    }
    for (int i = 26; i < 52; i++) {
        cout << "'" << static_cast<char>('a' + i - 26) << "'  || Count : " << CharHash[i] << endl;
    }
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

int GetWordCount(const string& str){
    // Word count using Hash table
    unordered_map<string, int> WordCount = HashCount(str);
    // Print
    int count = 0;
    for (const auto& pair : WordCount){
        cout << "'" << pair.first << "'  || Count : " << pair.second << endl;
        count += pair.second;
    }
    return count;
}

int GetUniqueWordCount(const string& str){
    // Word count using Hash table
    unordered_map<string, int> UniqWordCount = HashCount(str);
    int count = UniqWordCount.size(); 
    return count;
}

int GerWordCount_OneWord(const string& str, const char * myWord){
    // Word count using Hash table
    int count = 0;
    unordered_map<string, int> WordCount = HashCount(str);
    /*
    string searchWord(myWord);
    for (char& c : searchWord) {
        c = tolower(c);
    }
    */

    for (const auto& pair : WordCount){
        //if (pair.first == searchWord){
        if (pair.first == myWord){
            cout << "'" << pair.first << "'  || Count : " << pair.second << endl;
            count = pair.second;
        }
    }
    if (count == 0){
        cout << "Sorry, can't search input word." << endl;
    }
    return count;
}

int main(void){
    
    string input = "Hello World. I am Lee. My world is a Big WORLD.";
    //cout << "Enter a string : ";
    //getline(cin, input);
    // Count Word
    int word_count = GetWordCount(input);
    int uniq_count = GetUniqueWordCount(input);
    int one_count = GerWordCount_OneWord(input, "world");

    cout << "Get word count : " << word_count << endl;
    cout << "Get Unique word count : " << uniq_count << endl;
    cout << "Get One word count : " << one_count << endl;
    return 0;
}
