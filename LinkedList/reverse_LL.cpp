#include<iostream>
using namespace std ;

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

// insertion
void insert(Node* &head,Node* &tail,int d){
    Node* temp = new Node(d);
    if(head==NULL){
        head = temp;
        tail = temp;
        return ;
    }
    tail->next = temp;
    tail = temp;
}

// reverse LL
void reverse(Node* &head,Node* &tail,int n){
    int i=1;
    if(head->next == NULL) return ;

    Node* temp;
    while(i<n){
        temp = head;
        head = head->next;
        temp->next = tail->next;
        tail->next = temp;
        i++;
    }
    temp=tail;
    while(temp->next != NULL) temp = temp->next;

    tail = temp;

}

// reverse by recursion
void reverse_rr(Node* &head, Node* curr, Node* prev){
    // base case
    if(curr == NULL){
        head = prev;
        return ;
    }

    Node* forward = curr->next;
    
    reverse_rr(head,forward,curr);
    curr->next = prev;

}

void print(Node* head){

    Node* temp = head;
    while(temp != NULL){
        cout<<"->"<<temp->data;
        temp = temp->next;
    }

}
int main(){
    Node* head = NULL;
    Node* tail = NULL;

    int n;
    cout<<"enter number of nodes : ";
    cin>>n;
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<"enter node "<<i<<" : ";
        int val;
        cin>>val;
        insert(head,tail,val);
        cout<<endl;
    }

    // reverse(head,tail,n);
    Node* curr = head;
    Node* forward = head;
    Node* prev = NULL;
    reverse_rr(head,curr,prev);
    print(head);
    
    return 0;
}