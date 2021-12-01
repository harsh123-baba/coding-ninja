#include<iostream>
using namespace std;


class Fraction{
    private:
    int num;
    int den;
    public:
    Fraction(int num, int den){
        this->num = num;
        this->den = den;
    }
    void Print(){
    if(num==1 && den == 1){
        cout<<1<<endl;
        return;
    }
        cout<<num<<" / "<<den<<endl;
    }

    Fraction& operator+=(Fraction const &f){
        int newNum = num*f.den + den *f.num;
        int newDen = den*f.den;
        num = newNum;
        den = newDen;
        Fraction(num, den);
        solved();
        return *this;
    }


    int solved();
    void Addition(Fraction f2);
    void Multi(Fraction f2);
};
void Fraction :: Addition(Fraction f2){
    int newNum = this->num * f2.den + this->den *f2.num;
    int newDen = this->den * f2.den;
    this->num = newNum;
    this->den = newDen;
}



void Fraction :: Multi(Fraction f2){
    int newNum = this->num * f2.num;
    int newDen = this->den * f2.den;
    this->num = newNum;
    this->den = newDen;
}


int Fraction :: solved(){
    
    if(num==0){
        return 0;
    }
    if(den==0){
        cout<<"Sale kya de diya yeh Infinite answer aayega iska"<<endl;
        return 0;
    }
    int count =1;
    while(count<=num && count<=den){
        if(num%count ==0 && den%count==0){
            num = num/count;
            den = den/count;
        }
        count++;
    }
    return 0;
}

int main(){
    Fraction f(10, 20);
    Fraction f1(10, 40);
    (f+=f1)+=f1;
    f.solved();
    f.Print();
}