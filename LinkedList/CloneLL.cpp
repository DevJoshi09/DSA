// Clone a linked list next and randome pointer
#include<iostream>
using namespace std;
#include<unordered_map>

class Node{
    public:
        int data;
        Node* next;
        Node* randome;

        Node(int data){
            this->data = data;
            this->next = NULL;
            this->randome = NULL;
        }
};

void insert(Node* &head, Node* &tail, int val){
    Node* temp = new Node(val);
    if(head == NULL){
        head = temp ;
        tail = temp;
    }else{
        tail->next = temp;
        tail = temp;
    }
}
Node* Randome(Node* head, int indx){
    Node * temp = head;
    while(indx > 1 && temp != NULL){
        temp = temp->next;
        indx--;
    }
    return temp;
}

// clone Node
Node* CloneOriginalNode(Node* head){
    // step 1 : clone list
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;
    while(temp!= NULL){
        insert(cloneHead,cloneTail,temp->data);
        temp = temp->next;
    }
    // step 2: create a map
    unordered_map <Node*,Node*>oldToNew;

    temp = head;
    Node* temp2 = cloneHead;

    while(temp != NULL && temp2 != NULL){
        oldToNew[temp] = temp2;
        temp = temp->next;
        temp2 = temp2->next;
    }
    // step 3: now copy the randome pointer of original list
    temp = head;
    temp2 = cloneHead;

    while(temp != NULL && temp2 != NULL){
        
        // temp->randome --> temp2 ki value 
        temp2->randome = oldToNew[temp->randome];

        temp = temp->next;
        temp2 = temp2->next;
    }

    return cloneHead;
}
void print(Node* tail){

    while(tail != NULL){
        cout<<"-> | "<<tail->data<<" "<<tail->randome->data<<" | ";
        tail = tail->next;
    }
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;

    int n;
    cout<<" Enter the size of Linked List : ";
    cin>>n;

    for(int i = 1; i<=n;i++){
        int val;
        cin>>val;   
        insert(head,tail,val);
    }
    tail = head;
    cout<<"Enter the Randome Pointer \n";
    for(int i = 1; i<=n;i++){
        int indx;
        cin>>indx;
        Node* temp = Randome(head,indx);
        tail->randome = temp;
        tail = tail->next;
    }

    // Clone
    Node*cloneNode = CloneOriginalNode(head);
    print(cloneNode);

    return 0;
}