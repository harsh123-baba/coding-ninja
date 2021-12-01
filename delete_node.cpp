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

int length(Node * head){
    int count=0;
    while(head!=NULL){
        count++;
    }
    return count;
}
void Insert(Node* head, int x, int i){
    Node * temp = head;
    Node * newNode = new Node(x);
    int count =0;
    while(temp!= NULL && count< i-1){
        temp = temp->next;
        count++;
    }
    if(temp!=NULL){
        Node *a = temp->next;
        temp->next = newNode;
        newNode->next = a;
    }
}

int Delete(Node *head , int i ){
    int x;
    int count=0;
    Node * temp=head;
    Node *prev=NULL;
    while(temp!=NULL && count<i){
        count++;
        prev = temp;
        temp = temp->next;
    }
    if(temp!=NULL){
        Node *a = temp->next;
        x = temp->data;

        prev->next = a;
        delete temp; 
    }
    return x;
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

    Insert(head, 1000, 2);
    cout<<Delete(head, 1)<<endl;;
    Print(head);
}
