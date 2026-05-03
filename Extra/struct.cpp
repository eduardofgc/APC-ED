#include <iostream>

struct student{
    std::string name;
    double grade;
    bool enrolled;
};

void change_grade(student &subject){
    subject.grade = 10;
}

int main (){
    student A;

    std::cin >> A.name;
    std::cin >> A.grade;
    A.enrolled = true;

    change_grade(A);

    std::cout << A.name << "\n" << A.grade;

    return 0;
}