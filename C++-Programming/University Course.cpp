#include <iostream>
#include <vector>
#include <algorithm> // for std::sort

using namespace std;
const int MAX_COURSES = 5;
const int MAX_STUDENTS = 10;

// Student Class
class Student {
private:
    string name;
    int studentID;
public:
    Student(const string& studentName, int ID)
        : studentID(ID), name(studentName) {}

    virtual void DisplayInfo() const {
        cout << "Student ID: " << studentID << " || Name: " << name;
    }

    string GetName(){
        return name;
    }

    virtual ~Student() {}
};

// Undergraduate Student Class
class UndergraduateStudent : public Student {
private:
    int year;
public:
    UndergraduateStudent(const string& studentName, int ID, int studentYear)
        : Student(studentName, ID), year(studentYear) {}

    void DisplayInfo() const override {
        Student::DisplayInfo();
        cout << " || Type: Undergraduate || Year: " << year << endl;
    }
};

// Graduate Student Class
class GraduateStudent : public Student {
private:
    string researchTopic;
public:
    GraduateStudent(const string& studentName, int ID, const string& topic)
        : Student(studentName, ID), researchTopic(topic) {}

    void DisplayInfo() const override {
        Student::DisplayInfo();
        cout << " || Type: Graduate || Research Topic: " << researchTopic << endl;
    }
};

// Course Class
class Course {
protected:
    string courseName;
    int courseID;
    vector<Student*> enrolledStudents;
public:
    Course(const string& cName, int cID)
        : courseID(cID), courseName(cName) {}

    void EnrollStudent(Student* student) {
        enrolledStudents.push_back(student);
    }

    string ShowStudent() const{
        string studentList;
        for (Student* student : enrolledStudents){
            studentList += student->GetName() + ", ";
        }
        return studentList;
    }

    virtual void DisplayInfo() const {
        cout << "Course ID: " << courseID << " || Name: " << courseName << " || Students: " << ShowStudent();
    }

    virtual ~Course() {
        for (Student* student : enrolledStudents) {
            delete student;
        }
    }
};

// Programming Course Class
class ProgrammingCourse : public Course {
private:
    string programmingLanguage;
public:
    ProgrammingCourse(const string& cName, int cID, const string& language)
        : Course(cName, cID), programmingLanguage(language) {}

    void DisplayInfo() const override {
        Course::DisplayInfo();
        cout << "|| Type: Programming || Language: " << programmingLanguage << endl;
    }
};

// Literature Course Class
class LiteratureCourse : public Course {
private:
    string author;
public:
    LiteratureCourse(const string& cName, int cID, const string& bookAuthor)
        : Course(cName, cID), author(bookAuthor) {}

    void DisplayInfo() const override {
        Course::DisplayInfo();
        cout << "|| Type: Literature || Author: " << author << endl;
    }
};

// University Class
class University {
private:
    Course* coursesArr[MAX_COURSES];
    int numCourses;
public:
    University() : numCourses(0) {}		// Constructor

    ~University() {						// Destructor
        for (int i = 0; i < numCourses; i++) {
            delete coursesArr[i];
        }
    }

    void AddCourse(Course* course) {
        if (numCourses < MAX_COURSES) {
            coursesArr[numCourses++] = course;
        }
        else {
            cout << "Maximum course limit reached. Cannot add more." << endl;
            delete course;
        }
    }

    void DisplayCourses() const {
        for (int i = 0; i < numCourses; i++) {
            coursesArr[i]->DisplayInfo();
        }
    }
};

int main(void) {
    University MyUniversity;
    Course* ptr;

    ptr = new ProgrammingCourse("Introduction to C++", 1001, "C++");
    ptr->EnrollStudent(new UndergraduateStudent("Alice", 10001, 2));
    ptr->EnrollStudent(new GraduateStudent("Bob", 10002, "Object-Oriented Programming"));
    MyUniversity.AddCourse(ptr);

    ptr = new LiteratureCourse("Shakespearean Literature", 1002, "William Shakespeare");
    ptr->EnrollStudent(new UndergraduateStudent("Charlie", 10003, 3));
    ptr->EnrollStudent(new GraduateStudent("David", 10004, "Elizabethan Drama"));
    MyUniversity.AddCourse(ptr);

    cout << "University Courses Information:" << endl;
    MyUniversity.DisplayCourses();

    return 0;
}
