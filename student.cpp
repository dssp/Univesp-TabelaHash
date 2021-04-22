#include "student.h"

    Student::Student(){
        ra = -1;
        name = "";
    };

    Student::Student(int r, string n){
        ra = r;
        name = n;
    };

    int Student::getRA(){
        return ra;
    };

    string Student::getName(){
        return name;
    };
