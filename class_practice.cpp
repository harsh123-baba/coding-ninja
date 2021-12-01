#include<iostream>
using namespace std;

class Student
{
    private:
        int age;
// if i dont mention the access modifier then by defaul they become private members 
// to access private member we are going to test display fxn.
// i can use getter and setter methods to access these variables

    public:
        int roll;
        // Student(int roll, int age){
        //     this.roll = roll;
        //     this.age = age;
        // }
        void Display(){
            cout<<age<<" "<<roll;
        }

        int getter(){
            return age;

        }
        void Setter(int a){
            age = a;
        }
};


int main(){
    //static object
    Student s;

    s.roll = 27;
    s.Setter(21);
    s.Display();

    //Dynamic Object

    Student *s1 = new Student;
    (*s1).roll = 90;
    cout<<endl<<(*s1).roll<<endl;
    s1->roll = 90;
    cout<<endl<<s1->roll<<endl;
    
}