#include<iostream>
using namespace std;

class Stack{
    int *data;
    int capacity;
    int top;
    public:
    Stack(){
        data = new int[capacity];
        capacity = 4;
        top = 0;
    }
    int size(){
        return top;
    }

    bool isEmpty(){
        return top==0;
    }
    void push(int x){
        if(top == capacity){
            int * newData = new int[2 * capacity];
            for(int i = 0; i<capacity; i++){
                newData[i] = data[i];
            }
            data = newData;
            capacity *= 2;
        }
        data[top] = x;
        top++;
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
        // return 0;
    }

};



int main(){
    Stack s;
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
    cout<<s.pop()<<endl;


}