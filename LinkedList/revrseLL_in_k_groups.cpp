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

// reverse node in k groups
    Node* reverseNodeInKGroups(Node* head,int k){
        if(head == NULL){
            return NULL;
        }

        // if size of group is smaller than k
        Node* temp = head;
        int cnt = 0;
        while(temp != NULL && cnt<=k){
            cnt++;
            temp = temp->next;
        }
        if(cnt < k){
            return head;
        }

        // node to traverse + reverse list
        Node* prev = NULL;
        Node* curr = head;
        Node* forward = NULL;
        int count = 0;

        // reversing nodes 
        while(curr != NULL && count<k){

            // assign forward to next node, so that we can keep track after reversing node
            forward = curr->next;

            // changing direction of current node
            curr->next = prev;
            
            prev = curr;
            curr = forward;
            count++;
        }

        // if next element is not null
        if(forward != NULL){
            head ->next = reverseNodeInKGroups(forward,k);
        }

        return prev;
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
    int k;
    cout<<"Enter group length : ";
    cin>>k;

    Node* temp = reverseNodeInKGroups(head,k);
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    return 0;
}

/*
    Node* reverse(Node* curr, int k){
        Node* prev = NULL;
        Node* forward = NULL;
        int count = 0;

        // reversing nodes 
        while(curr != NULL && count<k){

            // assign forward to next node, so that we can keep track after reversing node
            forward = curr->next;

            // changing direction of current node
            curr->next = prev;
            
            prev = curr;
            curr = forward;
            count++;
        }
    return curr;
}

void insertAtTail(Node* &ansNode, Node* &ansTail, Node* &reversedNode){
    if(ansNode == NULL){
        ansNode = reversedNode;
        ansTail = reversedNode;
        return ;
    }
    ansTail->next = reversedNode; 

    while(reversedNode->next != NULL){
        reversedNode = reversedNode->next;
    }
    ansTail = reversedNode;
}

Node* reverseNodeInKGroups(Node* head,int k){
    Node* temp = head;
    Node* curr = head;
    int count = 0;

    // making node to return a reverse string 
    Node* ansNode = NULL;
    Node* ansTail = NULL;

    while(temp != NULL){
        if(count == k){
            Node* temphead = reverse(curr,k);
            insertAtTail(ansNode,ansTail,temphead);
            count=0;
            curr = temp->next;
        }
        temp = temp->next;
        count++;
    }
    return ansNode;
}
*/