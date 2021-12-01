#include<iostream>
using namespace std;


class Polynomial{
    private:
        int *data;
        int capacity;
    public:
    Polynomial(){
       data = new int[capacity];
       capacity = 5;
    }
    
    void add(int i, int c){
        for(int j=0; j<capacity ; j++){
            data[i] = 0;
        }
        if(i>= capacity){
            int *newData = new int[2*capacity];
            for(int j = 0; j<capacity; j++){
                newData[j] = data[j];

            }
            delete [] data;
            data = newData;
        }
        data[i] = c;
    }

    //copy constructor
    Polynomial (Polynomial const &p){
        // this->data = p.data; //shallo copy
        this->data = new int[capacity];
        for(int i =0; i<capacity ; i++){
            this->data[i] = p.data[i];
        }   
        this->capacity = p.capacity;
    }




    void Print(){
        for(int i = 0; i<capacity; i++){
            if(data[i]!=0){
                cout<<data[i] <<"x" <<"^"<<i<<" + ";
            }
        }
    }

    void coef_edit(int i, int coef){
        data[i] = coef;
    }

    //copy assignment
    void operator=(Polynomial const &p){
        this->data = new int[capacity];
        for(int i =0; i<capacity; i++){
            this->data[i] = p.data[i];
        }
    }

};

int main(){
    Polynomial p;
    p.add(2, 4);
    p.add(1, 3);
    p.add(0, 4);
    p.Print();
    cout<<endl;
    
    Polynomial p1(p);
    p.coef_edit(2, 6);
    p.Print();
    cout<<endl;
    p1.Print();
    cout<<endl;


    Polynomial p3;
    p3 = p;
    p.coef_edit(2, 7);
    p.Print();
    cout<<endl;
    p3.Print();
    cout<<endl;
}