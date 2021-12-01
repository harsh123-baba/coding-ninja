#include<iostream>
using namespace std;

template<typename T>
class Queue{
    private:
    T *data;
    int size;
    int front;
    int rear;
    int capacity;

    public:
    Queue(int s){
        front = -1;
        rear = 0;
        size = 0;
        data = new T[s];
        capacity = s;
    }

    int getsize(){
        return size;
    } 
    bool isEmpty(){
        return size ==0;
    }
    void enqueue(int x){
        if(size == capacity){
            cout<<"Overflow"<<endl;
            return;
        }
        else{
            data[rear] = x;
            rear = (rear+1)% capacity;
            if(front==-1){
                front=0;
            }
            size++;
        }
    }

    int dequeue(){
        if(size==0){
            cout<<"Under flow";
            return 0;
        }
        int x = data[front];
        front++;
        return x;
    }
};

int main(){
    Queue<int> q(4);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

}