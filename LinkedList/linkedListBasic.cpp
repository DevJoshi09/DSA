#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

};

// insertion of new node at begin or head
void InsertAtHead(Node* &head, int d){

    // create new temporary node
    Node* temp = new Node(d);
    // first make link 
    temp->next = head;
    // then asign head to temp
    head = temp;
}

// insertion at middle 
void InsertionAtMiddle(Node* &head,int pos, int d){
    // insertion at start 
    if(pos == 1){
        InsertAtHead(head,d);
        return ;
    }

    Node* temp = head;
    int cnt = 1;
    while(temp != NULL && cnt < pos -1){
        temp = temp->next;
        cnt += 1;
    }

    Node* mid = new Node(d);
    mid->next = temp->next ;
    temp->next = mid;
}

// insertion at end or tail
void InsertionAtTail(Node* &head, int d){
    // create a temp node
    Node* temp = head;
    // traver till tail
    while(temp->next!=NULL){
        temp=temp->next;
    }

    Node* tail = new Node(d);
    temp->next = tail;
    tail->next = NULL;

}

// traversal in linked list
void Traverse(Node* &head){

    Node* temp = head;

    while(temp != NULL){
        cout<<"->";
        cout<<temp->data;
        temp = temp->next;
    }
    cout<<endl;
}
int main(){

    // create an object of node
    Node* node1 = new Node(9);
    // cout<<node1->data<<endl<<node1->next<<endl;

    Node* head = node1;


    int d = 10;
    InsertAtHead(head,d);
    Traverse(head);


    d = 12;
    InsertionAtTail(head,d);
    Traverse(head);


    d = 11;
    int pos = 1;
    InsertionAtMiddle(head,pos,d);
    Traverse(head);
    return 0;
}