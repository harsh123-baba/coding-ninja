#include<iostream>
using namespace std;

class Node {
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
    while(data!= -1){
        Node * newNode = new Node(data);
        if(head == NULL){
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


Node * oddEven(Node * head){
        Node * oddh = NULL;
        Node * oddt = NULL;
        Node * evenh = NULL;
        Node * event = NULL;
    while(head!=NULL){
        if(head->data % 2 == 0){
            if(evenh == NULL){
                evenh = head;
                event = head;
                head = head->next;
            }
            else{
                event ->next = head;
                event = head;
                head = head ->next;
            }

        }
        else{
            if(oddh == NULL){
                oddh = head;
                oddt = head;
                head = head->next;
            }
            else{
                oddt->next = head;
                oddt = head;
                head = head->next;
            }
        }
    }
    oddt->next = evenh;
    return oddh;
}

void Print(Node * head ){
    while(head != NULL){
        cout<<head->data <<" ";
        head = head->next;

    }
    cout<<endl;
}


int main(){
    Node * head = TakeInput();
    Print(head);
    Node * head2 = oddEven(head);
    Print(head2);
}