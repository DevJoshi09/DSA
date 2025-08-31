// Remove cycle from linked list
#include<iostream>
#include<map>
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

void insert(Node* &head,Node* &tail, int value){
    Node* temp = new Node(value);
    temp->next = head;
    if(head==NULL){
        head = temp;
        tail= temp;
    }
    tail->next = temp;
    tail = temp;
}

// cycle remove algorithm
void getStartingNode(Node* slow, Node* &fast){
    while(slow != fast){
        fast = fast->next;
        slow = slow->next;
    }
    while(fast->next != slow){
        fast = fast->next;
    }

    cout<<"starting node of circular LL: "<<slow->data;
    fast->next = NULL;
}
    // -> floyd's algo
void cycleRemoval(Node* &head){

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL){

        fast = fast->next;
        if(fast != NULL) fast = fast->next;

        slow = slow->next;
        
        if(slow == fast) break;
    }
    // cout<<slow->data;
    slow = head;
    getStartingNode(slow,fast);
}

void print(Node* head){

    Node* temp = head;
    do{
        cout<<temp->data;
        temp = temp->next;
    }while(temp != head);

}
int main(){
    Node* head=NULL;
    Node* tail=NULL;
    int n;
    cout<<"enter number of nodes : ";
    cin>>n;
    for(int i=1;i<=n;i++){
        insert(head,tail,i);
    }
    print(head);
    cout<<endl;
    cycleRemoval(head);

    cout<<endl;

    
    return 0;
}