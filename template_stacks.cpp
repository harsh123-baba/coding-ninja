#include<iostream>
using namespace std;


template <typename T>
class Stack{
    int capacity;
    int top;
    T *data;
    public:
    Stack(){
        capacity = 4;
        top = 0;
        data = new T[capacity];
    }
    int size(){
        return top;
    }
    bool isEmpty(){
        return top==0;
    }
    void push(T x){
        if(capacity == top){
            T *newdata = new T[capacity*2];
            for(int i=0; i<capacity; i++){
                newdata[i] = data[i];
            }
            capacity *= 2;
            data = newdata;
        }
        data[top] = x;
        top++; 
    }
    T pop(){
        if(top==0){
            cout<<"Underflow"<<endl;
            return 0;
        }
        else{
            top--;
            return data[top];
        }
    }

};

int main(){
    Stack<char> s;
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;

}