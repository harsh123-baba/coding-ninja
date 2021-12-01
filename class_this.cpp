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

// Default constructor.
    Student(){
        cout<<"Constructor called"<<endl;
    }
//copy Constructor

    //this -> holds the current address of current object

    Student(int roll, int age){
        cout<<"This is the parameterized constructor"<<endl;
    // "this" is the pointer keyword so we can not call it on "."
    //we have to use "->"
        // this.roll = roll;
        // this.age = age;
        this->age = age;
        this->roll = roll;
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
    Student s2(s1);
    // i want all the data from s1 to s2;
    // copy consreuctor called
    // s2.Student(s1); // but we dont initize this 
    //this is in bulit constructor

// there are no constructor is called for s2. actually s2 calls copy constructor thats why that line us not coming

    s2.Display();



    Student *s3 = new Student(s2);
    s3->Display();
    Student *s4 = new Student(*s3);
    s4->Display();

}