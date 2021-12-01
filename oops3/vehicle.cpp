#include<iostream>
using namespace std;

class Vehicle{
    public:
    Vehicle(){
        cout<<"Vehicle class "<<endl;
    }
    Vehicle(int x, int y){
        cout<<"Parameterized Constructor "<<endl;
    }

};
class Car : public Vehicle{
    public:
    Car():Vehicle(){
        cout<<"Car Class"<<endl;
    }
    Car(int x, int y):Vehicle(x, y){
        cout<<"Car Class Parameterize Constructor "<<endl;
    }
    
};


class Honda : public Car{
    public:
    Honda(){
        cout <<"I am honda class Default constructor "<<endl;
        //Honda() stands for Honda():Car()
    }
    Honda(int x, int y):Car(x, y){
        cout<<"parameterized constructor"<<endl;
    }
    
};





int main(){
    // Vehicle v;
    Vehicle v(20, 40);
    Car c;
    Car c1(5, 6);
    Honda h();
}