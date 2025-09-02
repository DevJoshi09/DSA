// find palindrome in LL
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
void insert(Node* &head,int data){

    Node* temp = new Node(data);
    temp->next =NULL;

    if(head == NULL){
        head = temp ;
    }else{
        Node* tail = head;
        while(tail->next != NULL){
            tail = tail->next;
        }
        tail->next = temp;
        tail = temp;
    }
}
// copy Main list
Node* copy(Node* head){

    Node* newHead = NULL;
    Node* newtail = NULL;

    while(head != NULL){

        Node* temp = new Node(head->data);

        if(newHead == NULL){
            newHead = temp;
            newtail = temp;
        }else{
            newtail->next = temp;
            newtail = temp;
        }
        head = head->next;
    }
    return newHead;
}

//  reverse
void reverse(Node* &reverseNode){
    Node* prev = NULL;
    Node* curr = reverseNode;
    Node* forward = NULL;
    
    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    reverseNode = prev;
}

// Approach 1
bool palindrome(Node* head, Node* reverseHead){
    // base case
    if(head == NULL && reverseHead == NULL) {
        return true;
    }

    if(head->data != reverseHead->data){
        return false;
    }
    
    return palindrome(head->next,reverseHead->next);
}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    Node* head = NULL;

    int n;
    cout<<"enter n: ";
    cin>>n;

    for(int i=1;i<=n;i++){
        int data;
        cin>>data;
        insert(head,data);
    }
    
    // make a copy node so that we don't overrite the original node
    Node* reverseNode = copy(head);

    print(head);
    print(reverseNode);

    if(palindrome(head,reverseNode)) 
        cout<<"true";
    else 
        cout<<"false";
    return 0;
}