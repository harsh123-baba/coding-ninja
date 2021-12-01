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
    if(num==den){
        cout<<1<<endl;
        return;
    }
    
        cout<<num<<" / "<<den<<endl;
    }
    Fraction operator+(Fraction f2){
        int newNum = this->num * f2.den + this->den *f2.num;
        int newDen = this->den * f2.den;
        Fraction fNew(newNum, newDen);
        fNew.solved();
        return fNew;
    }

    //Here i pass F2 by refrence beacuse the reason behind that
    // i dont want to create much copies used pass by refrence  
    // But i want to avoid illegal changes by f2 so i make it constant
    //this is good practice for better codes.
    Fraction operator*(Fraction const &f2){
        int newNum = this->num * f2.num;
        int newDen = this->den * f2.den;
        Fraction fNew(newNum, newDen);
        fNew.solved();
        return fNew;
    }

    Fraction& operator++(){
        num = num+den;
        solved();
        return *this;
    }
    bool operator==(Fraction const &f2){
        return (num == f2.num && den == f2.den);
    }

    int solved();
    Fraction Addition(Fraction f2);
    void Multi(Fraction f2);
};

Fraction Fraction :: Addition(Fraction f2){
    int newNum = this->num * f2.den + this->den *f2.num;
    int newDen = this->den * f2.den;
    Fraction fNew(newNum, newDen);
    fNew.solved();
    return fNew;
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
    Fraction f1(20, 10);
    // Fraction f2 = f1.Addition(f);
    Fraction f2 = f1+f;
    Fraction f3 = f*f1;
    
    f2.Print();
    f3.Print();
    if(f1==f2){
        cout<<"Equal"<<endl;
    }
    else{
        cout<<"Not Equal"<<endl;
    }

}