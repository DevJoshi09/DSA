//  flatten a linked list 
// give list with child and next node 
// we need to sort the list

// merge sort in linked list
#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* child;

        Node(int data){
            this->data = data;
            this->next = NULL;
            this->child = NULL;
        }
};

// insert nodes
void insert(Node* &head, Node* &tail, int val){
    
    Node* temp = new Node(val);
    if(head == NULL){
        head = temp;
        tail = temp;
    }else{
        tail->next = temp;
        tail = temp;
    }
}
// insert child nodes
void insertChild(Node* &head, int val){
    
    Node* newNode = new Node(val);
    
    Node* temp = head;
    while(temp->child != NULL){
        temp = temp ->child;
    }
    temp->child = newNode;
}
Node* merge(Node* down,Node* right){
    Node* temp = down;

    while(temp->child != NULL){
        temp = temp->child;
    }
    temp->child = right;
    return down;

}
// flatten linked list
Node* flatten(Node* head){
    if(head == NULL){
        return head;
    }
    Node* down = head;    
    Node* right = flatten(head->next);
    down->next = NULL;

    Node* ans = merge(down,right);
    return ans;
}

int main(){
    int n;
    cout<<"Enter no of nodes : ";
    cin>>n;

    Node* head = NULL;
    Node* tail = NULL;

    int val;
    for(int i=1;i<=n;i++){
        cin>>val;
        insert(head,tail,val);
    }

    Node* temp = head;
    
    while (temp != NULL){
        cout<<"enter no of child : ";
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>val;
            insertChild(temp,val);
        }
        cout<<endl;
        temp = temp->next;
    }

    Node* right = head;
    while(right != NULL){
        Node* down = right;
        while(down != NULL){
            cout<<down->data<<"->";
            down = down->child;
        }
        cout<<"NULL";
        cout<<endl<< "| "<<endl;
        right = right->next;
    }

    Node* ans = flatten(head);
    temp = ans;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->child;
    }
    cout<<"NULL";

    return 0;
}