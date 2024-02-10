#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Question {
protected:
    string text;

public:
    Question(string text) : text(text) {}

    virtual void display() const {
        cout << text << endl;
    }

    virtual bool checkAnswer(const string& answer) const = 0;

    virtual ~Question() {}
};

class MultipleChoiceQuestion : public Question {
    vector<string> options;
    int correctAnswer;

public:
    MultipleChoiceQuestion(string text, const vector<string>& options, int correctAnswer)
        : Question(text), options(options), correctAnswer(correctAnswer) {}

    void display() const override {
        Question::display();
        for (int i = 0; i < options.size(); ++i) {
            cout << i + 1 << ". " << options[i] << endl;
        }
    }

    bool checkAnswer(const string& answer) const override {
        int answerIndex = stoi(answer) - 1;
        return answerIndex == correctAnswer;
    }
};

class TrueFalseQuestion : public Question {
    bool correctAnswer;

public:
    TrueFalseQuestion(string text, bool correctAnswer)
        : Question(text), correctAnswer(correctAnswer) {}

    void display() const override {
        Question::display();
        cout << "1. True" << endl;
        cout << "2. False" << endl;
    }

    bool checkAnswer(const string& answer) const override {
        int answerInt = stoi(answer);
        return (answerInt == 1 && correctAnswer) || (answerInt == 2 && !correctAnswer);
    }
};

class ShortAnswerQuestion : public Question {
    string correctAnswer;

public:
    ShortAnswerQuestion(string text, string correctAnswer)
        : Question(text), correctAnswer(correctAnswer) {}

    bool checkAnswer(const string& answer) const override {
        return answer == correctAnswer;
    }
};

class Quiz {
    vector<Question*> questions;

public:
    ~Quiz() {
        for (Question* q : questions) {
            delete q;
        }
    }

    void addQuestion(Question* question) {
        questions.push_back(question);
    }

    void runQuiz() const {
        int score = 0;
        string answer;

        for (const auto& question : questions) {
            question->display();
            cout << "Your answer: ";
            getline(cin, answer);

            if (question->checkAnswer(answer)) {
                cout << "Correct!" << endl;
                ++score;
            } else {
                cout << "Wrong!" << endl;
            }
            cout << endl;
        }

        cout << "Your score: " << score << " out of " << questions.size() << endl;
    }
};

int main() {
    Quiz quiz;

    quiz.addQuestion(new MultipleChoiceQuestion(
        "What is the capital of France?",
        vector<string>{"Paris", "London", "Berlin", "Madrid"}, 0));

    quiz.addQuestion(new TrueFalseQuestion(
        "The sky is blue.", true));

    quiz.addQuestion(new ShortAnswerQuestion(
        "Name a programming language that's also a gem.",
        "Ruby"));

    quiz.runQuiz();

    // The Quiz destructor automatically cleans up the questions
    return 0;
}