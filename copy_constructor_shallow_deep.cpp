#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Student{
    int age;
    public:
    char *Name;
        Student(int age, char *Name){
            this->age = age;
    //Shallow Copy   //not a right way to deal
            // this->Name = Name;
    //Deep copy Better way to do it so dude;
            this->Name = new char[strlen(Name)+1];
            strcpy(this->Name, Name);
        }

        //Copy Constructor
        Student(Student const &s){
            this->age = s.age;
            this->Name = s.Name; //Shallow Copy
            // this->Name = new char[strlen(Name)+1];
            // strcpy(this->Name , s.Name);
        }


        void Display(){
            cout<<Name<<" "<<age<<endl;
        }
};


int main(){
    char Name[] = "Harsh";
    Student s1(10, Name);
    s1.Display();

    
    Student s2(s1);
    // s2.Name[1] = 'o'; //No impact anywhere dude
    s2.Display();
    // s1.Display(); //Here my s1.name  value also changed in shallow copy
    s1.Display();


}