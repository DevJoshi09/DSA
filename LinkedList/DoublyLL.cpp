#include<iostream>
using namespace std;

// doubly linked list
class Node{
public:

    Node* prev;
    int data;
    Node* next;
    // constructor
    Node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    // destructor
    ~Node(){
        int val = this->data;
        cout<<" memory free for node with data : "<<val<<endl;
    }
};

// count number of nodes
int countNode(Node* &head){
    Node* temp = head;
    int count =0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

// insertion at start
void InsertionAtStart(Node* &head,Node* &tail, int d){
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = head;
    }else{
        Node* temp = new Node(d);
        // link
        temp->next = head;
        head->prev = temp;
        temp->prev = NULL;
        head = temp;
    }
}

// insertion at end
void InsertionAtEnd(Node* &tail,int d){
    Node* temp = new Node(d);
    
    tail->next = temp;
    temp->prev = tail;
    temp->next = NULL;
    tail = temp;

}

// insert at position 
void InsertionAtMid(Node* &head,Node* &tail,int d,int pos){
    // insert at head
    if(pos == 1){
        InsertionAtStart(head,tail,d);
        return ;
    }
    int cnt = countNode(head);
    // insert at tail
    if(cnt < pos){
        InsertionAtEnd(tail,d);
        return ;
    }

    int i=1;
    Node* back = NULL;
    Node* curr = head;
    while(i<pos){
        back = curr;
        curr = curr->next;
        i++;
    }

    Node* temp = new Node(d);
    temp->next = curr;
    curr->prev = temp;
    back->next = temp;
    temp->prev = back;

}

//  deletion 
void deleteAtHead(Node* &head, Node* &tail){
    Node* temp = head;
    if(temp->next == NULL){
        delete temp;
        head = NULL;
        tail = NULL;
        return ;
    }

    temp->next->prev = NULL;
    head = temp-> next;
    temp->next = NULL;
    delete temp;
}

void deleteAtPos(Node* &head,Node* &tail, int pos){
    if(pos == 1){
        deleteAtHead(head,tail);
        return ;
    }

    Node* prev = NULL;
    Node* curr = head;
    int i=1;
    while(i<pos){
        prev = curr;
        curr = curr->next;
        i++;
    }
    if(curr->next == NULL){
        tail = prev;
    }

    prev ->next = curr->next;
    curr->prev = NULL;
    curr->next = NULL;
}




// print function
void print(Node* &head){
    
    Node* temp = head;
    while(temp != NULL){
        cout<<"->"<<temp->data;
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    
    // Node* node1 = new Node(1);

    // Node* head = node1;
    // Node* tail = node1;

    // when starting from empty node or making our own list
    Node* head = NULL;
    Node* tail = NULL;

    // insertion at start
    int d = 0;
    InsertionAtStart(head,tail,d);
    print(head);
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;
    // insertion at end
    d = 2;
    InsertionAtEnd(tail,d);
    print(head);
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;

    // insertion at position
    d = 9;
    InsertionAtMid(head,tail,d,4);
    print(head);

    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;

    //  deletion
    cout<<"print after deletion"<<endl;
    // deleteAtHead(head,tail);
    // print(head);

    // deleteAtHead(head,tail);
    // print(head);

    // deleteAtHead(head,tail);
    // print(head);


    deleteAtPos(head,tail,2);
    print(head);

    deleteAtPos(head,tail,2);
    print(head);

    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;
    return 0;
} 
