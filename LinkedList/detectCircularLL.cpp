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
// Approach 1
/*
    bool checkCircularLL(Node* head){
        if(head == NULL){
            return true;
        }

        Node* temp = head;
        do{
            temp = temp->next;

        }while(temp != NULL && temp != head);

        if(temp == head){

            return true;
        }
        return false;
    }
*/
// Approach 2
/*
    bool checkCircularLL(Node* head){
        if(head== NULL){
            return true;
        }
        map<Node*,bool>Visited;
        Node* temp = head;
        while(temp != NULL){

            if(Visited[temp]){
                return true;
            }
            Visited[temp] = true;
            temp = temp->next;
        }

        return false;
    }
*/

// Approach 3 - Floyd's Cycle detection
bool checkCircularLL(Node* head){
    if(head == NULL) return true;

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && slow != fast){
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
        }
        slow = slow->next;
    }

    if(slow == fast){
        return true;
    }
    return false;
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
    Node* temp = head;
    do{
        cout<<temp->data;
        temp = temp->next;
    }while(temp != head);

    cout<<endl;

    if(checkCircularLL(head)==true){
        cout<<"true";
    }else{
        cout<<"false";
    }
    return 0;
}