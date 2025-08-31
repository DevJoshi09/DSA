// remove du[licates form sorted linked list
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
            if(this->next != NULL){
                delete next;
                this->next = NULL;
            }
        }
};

void insert(Node* &head,Node* &tail, int value){
    Node* temp = new Node(value);
    temp->next = NULL;
    if(head==NULL){
        head = temp;
        tail= temp;
    }
    tail->next = temp;
    tail = temp;
}

// remove duplicates
void removeDuplicates(Node* &head){

    if(head == NULL || head->next == NULL){
        return ;
    }

    Node* curr = head;

    while(curr != NULL && curr->next != NULL){
        if(curr->data != curr->next->data){
            curr = curr->next;
        }else{
            Node* duplicate = curr->next;
            curr->next = duplicate->next;
            duplicate->next = NULL;
            delete duplicate;
        }
    }
   
}
void print(Node* head){

    Node* curr = head;

    while(curr != NULL){

        cout<<curr->data<<" ";
        curr = curr->next;
    }

}
int main(){
    int n;
    cout<<"enter number of Nodes : ";
    cin>>n;

    Node* head = NULL;
    Node* tail = NULL;
    while(n--){
        int value;
        cin>>value;
        insert(head,tail,value);
    }
    removeDuplicates(head);
    print(head);

    return 0;
}