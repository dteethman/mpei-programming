#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Student {
    public: 
    string group, name, gender;
    int year_of_brith, ph_mark, math_mark, it_mark;
    float scholarship;

    Student() {
        group, name, gender = "";
        year_of_brith, ph_mark, math_mark, it_mark = 0;
        scholarship = 0; 
    }

    void display() {
        cout << "\e[1m" << name << "\e[0m\n";
        cout << "Группа: " << "\e[1m" << group << "\e[0m\n";
        cout << "Год рождения: " << "\e[1m" << year_of_brith << "\e[0m\n";
        cout << "Пол: " << "\e[1m" << gender << "\e[0m\n";
        cout << "Оценка по физике: " << "\e[1m" << ph_mark << "\e[0m\n";
        cout << "Оценка по математике: " << "\e[1m" << math_mark << "\e[0m\n";
        cout << "Оценка по информатике: " << "\e[1m" << it_mark << "\e[0m\n";
        cout << "Стипендия: " << "\e[1m" << scholarship << "\e[0m\n";
    }

    float average_mark() {
        return (ph_mark + math_mark + it_mark) / 3.0;
    }
};

class StudentParser {
    private:
    string fileURL;

    public:
    StudentParser(string URL) {
        fileURL = URL;
    }

    vector<Student> parse(){
        vector<Student> students;

        ifstream file;
        file.open(fileURL);

        string group;
        string name;
        string year_of_brith;
        string gender;
        string ph_mark;
        string math_mark;
        string it_mark;
        string scholarship;
        while (getline(file, group, ';')) {
            Student student;
            student.group = group;
            getline(file, name, ';');
            student.name = name;
            getline(file, year_of_brith, ';');
            student.year_of_brith = stoi(year_of_brith);
            getline(file, gender, ';');
            student.gender = gender;
            getline(file, ph_mark, ';');
            student.ph_mark = stoi(ph_mark);
            getline(file, math_mark, ';');
            student.math_mark = stoi(math_mark);
            getline(file, it_mark, ';');
            student.it_mark = stoi(it_mark);
            getline(file, scholarship, '\n');
            student.scholarship = stof(scholarship);
            students.push_back(student);
        }

        file.close();
        return students;
    }
};

int main(void) {
    vector<Student> students;

    StudentParser parser("students.csv");
    students = parser.parse();

    for (int i = 0; i < students.size(); i++) {
        students.at(i).display();
        cout << endl;
    }

    cout << "\e[1m" << "Студенты со средним балом выше 4.5:" << "\e[0m\n";
    for (int i = 0; i < students.size(); i++) {
        if (students.at(i).average_mark() > 4.5) {
            cout << students.at(i).name << ", оценка по физике:  " << students.at(i).ph_mark << endl;
        }
    }

    cout << endl;

    return 0;
}
 