#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>

using namespace std;

class WordCounter {
private:
    string text;
    int CharHash[52] = {0};                 // Array to store character counts
    unordered_map<string, int> WordHash;    // Map to store word counts

public:
    
    WordCounter(const string & text) : text(text) {
        countWords();
        countChars();
    }
    //WordCounter() {}

    void InputText(const string & input){
        text = input;
        countWords();
        countChars();
    }

    int GetWordCount(){
        // Count Words
        int count = 0;
        for (const auto& pair : WordHash){
            //displayWords();
            count += pair.second;
        }
        cout << "Word Count: " << count << endl;
        return count;
    }

    int GetCharacterCount(){
        int count = 0;
        for (int i = 0; i < 52; i++){
            count += CharHash[i];
        }
        cout << "Character Count: " << count << endl;
        return count;
    }

    int GetUniqueWordCount(){
        int count = WordHash.size();
        cout << "Number of Unique Words: " << count << endl;
        return count;
    }

    int GetWordCount_OneWord(const char* myWord){
        int count = 0;
        for (const auto& pair : WordHash){
            if (pair.first == myWord){
                count = pair.second;
                cout << "The word(" << myWord << ") and appears " << count << " times" << endl;
            }
        }
        if (count == 0){
            cout << myWord << " can't find in input string." << endl;
        }
        return count;
    }

    void countChars() {
        for (char curr : text) {
            if (isalpha(curr)) {
                if (isupper(curr)) {
                    CharHash[curr - 'A']++;
                } else {
                    CharHash[curr - 'a' + 26]++;
                }
            }
        }
    }

    void countWords() {
        string currWord;

        for (char c : text) {
            if (isalpha(c) || isdigit(c)) {
                //currWord += std::tolower(c);
                currWord += c;
            } else if (!currWord.empty()) {
                WordHash[currWord]++;
                currWord.clear();
            }
        }
        if (!currWord.empty()) {
            WordHash[currWord]++;
        }
    }

    void displayChars() const {
        for (int i = 0; i < 26; i++) {
            cout << "'" << static_cast<char>('A' + i) << "'  || Count : " << CharHash[i] << endl;
        }
        for (int i = 26; i < 52; i++) {
            cout << "'" << static_cast<char>('a' + i - 26) << "'  || Count : " << CharHash[i] << endl;
        }
    }

    void displayWords() const {
        for (const auto& pair : WordHash) {
            cout << "'" << pair.first << "'  || Count : " << pair.second << endl;
        }
    }
};

int main() {
    string input = "Hello my World. My name is Lee. I'll go big World and wide World !";
    //WordCounter WC;
    //WC.InputText(input);
    WordCounter WC(input);    // initialization with input string
    WC.GetWordCount();
    WC.GetCharacterCount();
    WC.GetUniqueWordCount();
    WC.GetWordCount_OneWord("World");
    //WC.displayWords();
    

    return 0;
}
