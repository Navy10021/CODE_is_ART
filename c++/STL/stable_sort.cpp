#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Student{
    public:
        string name;
        int score;

    Student(const string& n, int s) : name(n), score(s) {}
};

bool cmp(const Student& a, const Student& b){
    return a.score < b.score;
}

int main(){
    vector<Student> students;

    students.push_back(Student("Lee", 100));
    students.push_back(Student("Kim", 100));
    students.push_back(Student("Park", 100));
    students.push_back(Student("Yoon", 80));
    students.push_back(Student("Lee", 70));
    students.push_back(Student("Won", 60));

    // 성적을 기준으로 Stable sort.
    stable_sort(students.begin(), students.end(), cmp);

    // 출력 
    for (const Student& s : students){
        cout << "Name : " << s.name << ", Score :" << s.score << "\n";
    }
}
