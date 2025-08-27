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
    
        ~Node(){
            int value = this->data;
            if(this->next != NULL){
                delete next;
                next = NULL;
            }
            cout<<"node deleted for value : "<<value<<endl;
        }
};


void insert(Node* &tail,int element,int data){
    // assume element is present
    if(tail == NULL){
        Node* newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;

    }else{

        Node* curr = tail;
        while(curr->data != element){
            curr = curr->next;
        }

        Node* temp = new Node(data);

        temp->next = curr->next;
        curr->next = temp;

    }
}

void print(Node* tail){

    Node* curr = tail->next;
    tail = curr;

    do{

        cout<<tail->data<<" ";
        tail = tail -> next;

    }while(tail != curr);

    cout<<endl;
}

// deletion
void deleteNode(Node* &tail, int value){
    if(tail == NULL){
        
        cout<<"List is empty ,please check it again."<<endl;
    }else{

        Node* prev = tail;
        Node* curr = tail->next;
        while(curr->data != value){
            prev = curr;
            curr = curr->next;
        }

        if(tail == curr){
            tail = prev;
        }

        prev ->next = curr->next;
        curr->next = NULL;
        delete curr;

    }
}


int main(){

    Node* tail = NULL;

    insert(tail,2,1);
    print(tail);
    
    insert(tail,1,2);
    print(tail);
    
    insert(tail,2,3);
    print(tail);

    insert(tail,3,4);
    print(tail);

    insert(tail,2,5);
    print(tail);

    insert(tail,2,2);
    print(tail);

    insert(tail,2,6);
    print(tail);

    // deletion
    deleteNode(tail,3);
    print(tail);

    deleteNode(tail,1);
    print(tail);


    return 0;
}