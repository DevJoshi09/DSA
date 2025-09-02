// sort a linked list with 0,1 & 2
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
        temp->next = NULL;
    }else{
        temp->next = head;
        head = temp;
    }
}

// Approach 1
/*
    void sort(Node* &head){
        int count_0 = 0, count_1=0, count_2=0;
        Node* temp = head;

        while(temp != NULL){
            if(temp->data == 0){
                count_0++;
            }else if(temp->data == 1){
                count_1++;
            }else{
                count_2++;
            }
            temp = temp->next;
        }

        temp = head;
        while(temp != NULL){
            if(count_0 != 0){
                count_0--;
                temp->data = 0;
            }else if(count_1 != 0){
                count_1--;
                temp->data = 1;
            }else{
                count_2--;
                temp->data = 2;
            }
            temp = temp->next;
        }
    }
*/
// Approach2
Node* sort(Node* head){
    Node* zeroNode=NULL;
    Node* oneNode=NULL;
    Node* twoNode=NULL;

    while(head != NULL){
        if(head->data == 0){
            insert(zeroNode,head->data);
        }else if(head->data == 1){
            insert(oneNode,head->data);
        }else{
            insert(twoNode,head->data);
        }
        head = head->next;
    }
    head = zeroNode;
    while(head->next != NULL){
        head = head->next;
    }
    head->next = oneNode;
    while(head->next != NULL){
        head = head->next;
    }
    head->next = twoNode;
    while(head != NULL){
        head = head->next;
    }

    return zeroNode;
}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    
}
int main(){
    Node* head = NULL;
    int n;
    cout<<"enter n: ";
    cin>>n;

    for(int i=1;i<=n;i++){
        int data;
        cin>>data;
        insert(head,data);
    }
    Node* temp = sort(head);
 
    

    print(temp);
    return 0;
}