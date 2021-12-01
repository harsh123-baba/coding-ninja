#include<iostream>
using namespace std;

class Student{
    private:
    int age;
    public:
    int roll;
    //when ever we call "Student s1" in main function then automatically a default constructor is being called
    //so s1.Student() the default constructor is automatically called
    //
    Student(){
        cout<<"Constructor called"<<endl;
    }
    Student(int r, int a){
        cout<<"This is the parameterized constructor"<<endl;
        roll = r;
        age = a;

    }
    void Display(){
        cout<<age<<" "<<roll<<endl;
    }
    int getAge(){
        return age;
    }
    void setAge(int a){
        age = a;
    }
};



int main(){
    Student s1;
    s1.roll = 20;
    s1.setAge(21);
    s1.Display();
//so outdated bro..

    //USE OF CONSTRUCTORS
    //Parameterized constructor ko call kr liya vro tune
    Student s2(12, 21);
    s2.Display();


    Student *s3 = new Student(27, 21);
    s3->Display();
    Student *s4 = new Student;
    s4->Display();

}