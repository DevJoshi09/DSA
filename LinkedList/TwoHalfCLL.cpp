// convert circular LL into two half circular LL

#include<iostream>
#include<cmath>
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
    temp->next = head;
    if(head==NULL){
        head = temp;
        tail = temp;
        temp->next = temp;
        return ;
    }
    tail->next = temp;
    tail = temp;
}
// print 
void print(Node* head){
    Node* temp = head;
    do{

        cout<<temp->data<<" ";        
        temp = temp->next;
    }while(temp != head);

    cout<<endl;
}
// CLL -> two half CLL
void twoHalf(Node* &head, int n){
    Node* half1 = head;
    Node* half2 = NULL;

    int len = 1;
    // first half
    while(len < n/2 && half1 != NULL){
        half1 = half1->next;
        len++;
    }
    half2 = half1->next;
    half1->next = head;
    half1 = head;

    // second half
    Node* head2 = half2;
    while(half2->next != head){
        half2 = half2->next;
    }
    half2->next = head2;

    print(half1);
    print(head2);
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    int n;
    cout<<"enter number of nodes : ";
    cin>>n;
    cout<<endl;
    for(int i=1;i<=n;i++){
        insert(head,tail,i);
    }
    print(head);
    twoHalf(head,n);
}