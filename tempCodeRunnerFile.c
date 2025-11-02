#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insert(Node* &head,int data){
    Node* temp = new Node(data);
    if(head == NULL){
        head = temp ;
    }else{
        Node* tail = head;
        while(tail->next != NULL){
            tail = tail->next;
        }
        tail->next = temp;
    }
}

Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL){
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

bool palindrome(Node* head, Node* reverseHead){
    if(head == NULL && reverseHead == NULL) 
        return true;

    if(head == NULL || reverseHead == NULL) 
        return false;

    if(head->data != reverseHead->data) 
        return false;

    return palindrome(head->next, reverseHead->next);
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

    // make a copy of head
    Node* temp = head;
    Node* copy = NULL, *tail = NULL;
    while(temp != NULL){
        Node* newNode = new Node(temp->data);
        if(copy == NULL){
            copy = newNode;
            tail = copy;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        temp = temp->next;
    }

    Node* reverseHead = reverse(copy);

    print(head);
    print(reverseHead);

    if(palindrome(head,reverseHead)) 
        cout<<"true";
    else 
        cout<<"false";

    return 0;
}
