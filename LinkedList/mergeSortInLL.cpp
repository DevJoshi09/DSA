// merge sort in linked list
#include<iostream>
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
// insert at nodes
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
// find mid from list
Node* findMid(Node* head){
    Node* slow = head;
    // start ahead so it return mid value in case of even no of nodes
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node* merge(Node* left, Node* right){

    Node* ans = new Node(-1);
    Node* temp = ans;

    while(left != NULL || right != NULL){

        if(left != NULL && right == NULL){
            temp ->next = left;
            temp = left;
            left = left->next;
            continue;
        }
        if(left == NULL && right != NULL){
            temp ->next = right;
            temp = right;
            right = right->next;
            continue;
        }

        if(left->data < right->data){
            temp ->next = left;
            temp = left;
            left = left->next;
        }else{
            temp ->next = right;
            temp = right;
            right = right->next;
        }
    }

    ans = ans->next;
    return ans;
}

// merge sort (main function)
Node* mergeSort(Node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    // find mid 
    Node* mid = findMid(head);

    // break linked list into two half, after finding mid
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;
    
    // recursive call to sort both half
    left = mergeSort(left);
    right = mergeSort(right);

    // merge both left and right half
    Node* result = merge(left,right);

    return result;
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

    // Merge Sort Algorithm (Divide and Conqure)
    Node* ans = mergeSort(head);

    Node* temp = ans;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL";

    return 0;
}