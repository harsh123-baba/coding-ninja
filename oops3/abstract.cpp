#include<iostream>
using namespace std;

class Vehicle{
    public:

    virtual void start()=0;

};

class Bus : public Vehicle{
    public:
    void start(){
        return;
    }

};

int main(){
    // Vehilce v();
    Bus b();
}