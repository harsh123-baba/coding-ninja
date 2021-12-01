#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Student{
    int age;
    char *Name;
    public:
        Student(int age, char *Name){
            this->age = age;
    //Shallow Copy   //not a right way to deal
            // this->Name = Name;
    //Deep copy Better way to do it so dude;
            this->Name = new char[strlen(Name)+1];
            strcpy(this->Name, Name);
        }
        void Display(){
            cout<<Name<<" "<<age<<endl;
        }
};


int main(){
    char Name[] = "Harsh";
    Student s1(10, Name);
    s1.Display();

    Name[1] = 'o';
    Student s2(21, Name);
    s2.Display();
    // s1.Display(); //Here my s1.name  value also changed in shallow copy
    s1.Display();


}