#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node * next;
    Node(int data){
        this->data = data;
        Node * next = NULL;
    }

};

Node * TakeInput(){
    int data;
    cin>>data;
    Node * head = NULL;
    Node * tail = NULL;
    while(data!=-1){
        Node * newNode = new Node(data);
        if (head == NULL){
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


void Print(Node * head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

//Using Recursion

Node * Reverse(Node * head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node * smallAns = Reverse(head->next);
    Node * temp = smallAns;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return smallAns;
}
int main(){
    Node * head = TakeInput();
    
    Print(head);
    Node * head1 = Reverse(head);
    Print(head1);
}