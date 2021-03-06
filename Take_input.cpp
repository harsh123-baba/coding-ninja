#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        Node * next = NULL;
    }
};

void Print(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;

}

Node * TakeInput(){
    int data;
    cin>>data;
    Node *head = NULL;
    Node *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head==NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        cin>>data;

    }
    return head;
}


int main(){
    Node * head = TakeInput();
    Print(head);
}
