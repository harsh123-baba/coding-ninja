#include<iostream>
using namespace std;

class Stack{
    private:
    int *data;
    int top;
    int capacity;
    public:

    Stack(int totalsize){
        data = new int[totalsize];
        top = 0;
        capacity = totalsize;
    }

    int size(){
        return top;
    }

    bool isEmpty(){
        return top==0;
    }

    void push(int x){
        if(top == capacity){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        else{
            data[top] = x;
            top++;
        }
    }
 
    int pop(){
        if(top==0){
            cout<<"Stack Underflow"<<endl;
            return 0;
        }
        else{
            top--;
            return data[top];
        }
    }
};


int main(){
    Stack s(4);
    s.push(1);
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);


    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
}