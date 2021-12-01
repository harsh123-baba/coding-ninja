#include<iostream>
using namespace std;


class Converter{
    private:
        int hr;
        int min;
        int sec;
    public:
    Converter(int sec){
        this->hr = sec/3600;
        sec = sec - this->hr*3600;
        this-> min = sec/60;
        int remainSec = sec - this->min * 60;
        this->sec = remainSec;
    }
    void Print(){
        cout<<this->hr<<" : "<<this->min<<" : "<< this->sec<<endl;
    }
};


int main(){
    Converter c(165654);
    c.Print();
}