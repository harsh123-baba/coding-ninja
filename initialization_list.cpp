#include<iostream>
using namespace std;

class Student{
    int age=10;
    const int roll;   // here roll picks a garbage vlaue and  constructor call will throw error;
    int &x;  // refrence variables are not initialize like that so we have to use initalization  list  
    
    public:
    Student(int age, int r) :age(age), roll(r), x(this->age){
        // this->age = age;
        //bhar wala age this->age hai and andr wala argument hai

    } 
    void Display(){
        cout<<age<<" "<<roll<<" "<<x<<endl;
    }

};




int main(){
    Student s(10, 1001);
    s.Display();
}