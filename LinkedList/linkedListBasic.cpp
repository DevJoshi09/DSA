// singly linked list
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

    // destructor 
    ~Node(){
        int value = this->data;
        // memory free
        if(this->next != NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory free for : "<<value<<endl;
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
    // void InsertionAtTail(Node* &head, int d){
    //     // create a temp node
    //     Node* temp = head;
    //     // traver till tail
    //     while(temp->next!=NULL){
    //         temp=temp->next;
    //     }

    //     Node* tail = new Node(d);
    //     temp->next = tail;
    //     tail->next = NULL;

    // }
void InsertionAtTail(Node* &tail,int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
    tail->next=NULL;
    
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

// deletion of node

void DeleteNode(Node* &head,Node* &tail, int pos){
    if(pos == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL; 
        // free space
        delete temp;

    }else{
        Node* prev = NULL;
        Node* curr = head;
        int count = 1;

        while(count++ < pos){
            prev = curr;
            curr = curr->next;
        }
        if(curr->next == NULL){
            tail = prev;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
        
        // or
        // prev->next = prev->next->next;
    }
}
int main(){

    // create an object of node
    Node* node1 = new Node(9);
    // cout<<node1->data<<endl<<node1->next<<endl;

    Node* head = node1;
    Node* tail = node1;

    // insertion at begin 
    int d = 10;
    InsertAtHead(head,d);
    // Traverse(head);

    // insertion at end
    d = 12;
    InsertionAtTail(tail,d);
    // Traverse(head);

    d = 13;
    InsertionAtTail(tail,d);
    // Traverse(head);
    

    // insertion at position
    d = 11;
    int pos = 3;
    InsertionAtMiddle(head,pos,d);
    Traverse(head);


    // deletion of nodes
    pos = 5;
    DeleteNode(head,tail,pos);
    Traverse(head);
    
    cout<<endl<<tail->data<<endl;


    return 0;
}