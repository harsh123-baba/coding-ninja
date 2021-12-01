#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Complex{
    private:
        int real;
        int img;
    public:
        Complex(int real, int img){
            this->real = real;
            this->img = img; 
        }
        void Print(){
            cout<<real <<" + j"<<img<<endl;
        }

        void Add(Complex c1){
            int newReal = this->real + c1.real;
            int newImg = this->img + c1.img;
            this->real = newReal;
            this->img = newImg;
        }
        void Multi(Complex f1){
            int newReal = this->real * f1.real + this->real *f1.img;
            int newImg = this->img * f1.real + this->img * f1.img;
            this->real = newReal;
            this->img = newImg;
        }

};

int main(){
    Complex c(1, 2);
    c.Print();
    Complex c1(2, 3);
    c.Add(c1);
    c.Print();
    c.Multi(c1);
    c.Print();

}