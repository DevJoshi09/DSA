// find middle Node in LL
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
void InsertAtHead(Node* &head, int d){

    // create new temporary node
    Node* temp = new Node(d);
    // first make link 
    temp->next = head;
    // then asign head to temp
    head = temp;
}

void print(Node* head){

    Node* temp = head;
    while(temp != NULL){
        cout<<"->"<<temp->data;
        temp = temp->next;
    }

    cout<<endl;
}
// int getMid(Node* head){
//     Node* temp = head;
//     int cnt = 1;
//     while(temp->next != NULL){
//         temp = temp->next;
//         cnt++;
//     }
//     int mid = (cnt/2);
//     return mid;
// }

void getMid(Node* head){
    // head = null || 1 node
    if(head == NULL || head->next == NULL){
        cout<<head<<endl;
        return ;
    }
    // 2 node 
    if(head->next->next == NULL){
        cout<<head->next->data<<endl;
        return ;
    }

    Node* fast = head;
    Node* slow = head;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
    }
    
    cout<<slow->data;
}

// void MiddleNode(Node* head){
    
//     int mid = getMid(head);
//     // cout<<cnt<<endl;
//     int cnt = 1;
//     Node* temp = head;
//     while(cnt <= mid){
//         temp=temp->next;
//         cnt++;
//     }
    
//     cout<<temp->data<<endl;

// }



int main(){
    Node* head = NULL;

    InsertAtHead(head,1);
    InsertAtHead(head,2); 
    InsertAtHead(head,3);
    InsertAtHead(head,4);
    // InsertAtHead(head,5);
    
    print(head);

    // MiddleNode(head);
    getMid(head);
}