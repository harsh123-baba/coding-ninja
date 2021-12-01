#include<iostream>
using namespace std;

class Student{
    private:
    static int totalStudent;
    public:
    int age;
    int roll;
    Student(){
        totalStudent++;
    }
    static int getStudents(){
        return totalStudent;
    }

};

int Student :: totalStudent = 0;


int main(){
    Student s, s1, s2,s3, s4;
    // cout<< Student::totalStudent;
    cout<< Student::getStudents()<<endl;

}