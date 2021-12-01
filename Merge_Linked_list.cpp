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


Node * Merge(Node * head1, Node * head2){
    Node * fh = NULL;
    Node * ft = NULL;
    while(head1!=NULL && head2!=NULL){
        if(head1->data <head2->data){
            if(fh==NULL){
                fh = head1;
                ft = head1;
                head1 = head1->next;
            }
            else{
                ft->next = head1;
                ft= head1;
                head1 = head1->next;
            }
        }
        else{
            if(fh==NULL){
                fh = head2;
                ft = head2;
                head2 = head2->next;
            }
            else{
                ft->next = head2;
                ft= head2;
                head2 = head2->next;
            }
        }
    }
    while(head1!=NULL){
        ft->next = head1;
        ft = head1;
    }
    while(head2!=NULL){
        ft->next = head2;
        ft = head2;
    }
    return fh;
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
    Node * head1 = TakeInput();
    Node  * head2 = Merge(head, head1);
    Print(head2);
}