// Merge two sorted linked list
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

// Approach 1
// insert head2 LL into head1 LL
Node* mergeSort(Node* head1,Node* head2){
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }
    Node* prev = head1;
    Node* curr = head1->next;

    while(curr != NULL && head2 != NULL){

        if(head2->data >= prev->data && head2->data <= curr->data){
            Node* temp = head2;
            head2 = head2->next;
            temp->next = prev->next;
            prev->next = temp;
            cout<<prev->data<<" "<<temp->data<<" "<<curr->data<<endl;
            prev = temp;

        }else{
            prev = curr;
            curr = curr->next;
        }
    }

    if(curr == NULL && head2 != NULL){
        prev->next = head2;
        prev = head2;
    }

    return head1;

}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    
}
int main(){
    Node* head1 = NULL;
    Node* head2 = NULL;

    int n;
    cout<<"enter n: ";
    cin>>n;

    for(int i=1;i<=n;i++){
        int data;
        cin>>data;
        insert(head1,data);
    }

    cout<<"enter n: ";
    cin>>n;
    for(int i=1;i<=n;i++){
        int data;
        cin>>data;
        insert(head2,data);
    }

    Node* temp = mergeSort(head1,head2);
    print(temp);

    return 0;
}