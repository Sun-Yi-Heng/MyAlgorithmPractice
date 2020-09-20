//
// Created by 孙一恒 on 2020/1/21.
//
#include <iostream>
#include "test_h.h"
#include <cmath>
#include <string.h>
using namespace std;


class Student
{
public:
    int id;
    char* name;
    double score;
    void printInfo()
    {
        cout << id << endl;
    }
    Student(const Student& obj);
    Student(double s, int i);
};

Student::Student(double s, int i):id(i), score(s)
{
    cout << "普通构造函数被调用!" << endl;
}

void externMethod();
extern int test_extern;

int getArray()
{
    int array[] = {1, 2, 3, 4};
    return *array;
}


Student::Student(const Student &obj)
{
    cout << "拷贝构造函数被调用!" << endl;
}

Student conTest(Student &student)
{
    student.printInfo();
    return Student(11.1, 232);
}

