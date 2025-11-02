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

void print(Node* head){

    while(head != NULL){
        cout<<"-> | "<<head->data<<" "<< head->randome->data <<" | ";
        head = head->next;
    }
}

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
// merge original list and clone list
void InsertInBetween(Node* &head,Node* &cloneHead){
    Node* curr1 = head;
    Node* forward1 = NULL;

    Node* curr2 = cloneHead;
    Node* forward2 = NULL;

   while( curr1 != NULL && curr2 != NULL){
        forward1 = curr1->next;
        curr1->next = curr2;

        forward2 = curr2->next;
        curr2->next = forward1;

        curr1 = forward1;
        curr2 = forward2;
   }

}
// copy the randome node
void copyRandome(Node* head){
    // base case
    if(head == NULL){
        return ;
    }
    head->next->randome = head->randome->next;
    copyRandome(head->next->next);

}

// De Attach both list
void deAttach(Node* &head,Node* &cloneHead){
    Node* temp1 = head;
    Node* temp2 = cloneHead;

    while(temp1 != NULL){
        temp1->next = temp2->next;
        temp1 = temp2->next;
        if(temp1 != NULL){
            temp2->next = temp1->next;
            temp2 = temp1->next;
        }
    }
    temp2->next = NULL;
}


// clone Node  ->(Main function of clone)
Node* CloneOriginalNode(Node* head){
    // step 1 : clone list
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;
    while(temp!= NULL){
        insert(cloneHead,cloneTail,temp->data);
        temp = temp->next;
    }

    // step 2: insert clone node in between original node
    InsertInBetween(head,cloneHead);

    // step 3: copy the the randome node to cloneNode in head
    copyRandome(head);

    // step 4: seprate both list
    deAttach(head,cloneHead);

    return cloneHead;
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

    print(head);
    cout<<endl;

    // Clone Nodes 
    
    Node*cloneNode = CloneOriginalNode(head);
    print(cloneNode);

    return 0;
}