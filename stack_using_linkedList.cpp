#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next = NULL;
    Node(int data){
        this->data = data;
        Node *next = NULL; 
    }
};

class Stack{
    private:
    Node * head;
    Node * tail;

    public:
    
    Stack(){
        head = NULL;
        tail = NULL;
    }
    
    int size(){
        int count;
        while(head!=NULL){
            count++;
            head = head->next;
        }
        return count;
    }
    
    bool isEmpty(){
        return head==NULL;
    }

    Node* push(int x){
        if(head == NULL){
            Node* newNode = new Node(x);
            head = newNode;
            tail = newNode;
        }
        else{
            Node* newNode = new Node(x);
            tail->next = newNode;
            tail = newNode;
        }
        return head;
    }
    int pop(){
        if(head == NULL){
            return 0;

        }
        else{
            
        }
    }
};

int main(){


}