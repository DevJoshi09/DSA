#include<iostream>
using namespace std;

class Node{

    public:
    // linked list details
        int data;
        Node* next;

    // constructor
        Node(int data){
            this->data = data;
            this->next = NULL;
        }

    // distructor
        ~Node(){
            int value = this->data;
            // memory free
            if(this->next != NULL){
                delete next;
                this->next=NULL;
            }
            cout<<"memory free for : "<<value<<endl;
        }

};
void print(Node* head,int top,int size){
    Node* temp = head;
    while(temp!=NULL){
        if(top == 0) cout<<"|_"<<temp->data<<"_|"<<endl;
        else cout<<"| "<<temp->data<<" |"<<endl;
        top--;
        temp=temp->next;
    }
}

class stack{
    private:
        int top;
        Node* head;
        int size;

    public:
        stack(int size){
            this->size = size;
            head = NULL;
            top=-1;
        }
        // insertion
        void push(int data){
            top++;
            if(top < size ){
                Node* temp = new Node(data);
                temp->next = head;
                head = temp;
                
                if(top == size - 1) cout<<"|_"<<temp->data<<"_|"<<endl;
                else cout<<"| "<<temp->data<<" |"<<endl;

            }else{
                cout<<"Stack over flow...";
            }
        }
        // deletion 
        void pop(){
            // cout<<endl;
            if(head == NULL){
                cout<<endl<<"Stack UnderFlow...";
            }else{
                
                Node* temp = head;
                head = head->next;
                top--;
                temp->next = NULL;
                delete temp;
                print(head,top,size);
            }
        }
        // top element
        void Top(){
            cout<<head->data;
        }
};
int main(){
    int n;
    cout<<"Enter size of stack :";
    cin>>n;
    stack stk(n);

    stk.push(1);
    stk.push(2);
    stk.push(2);
    stk.pop();
    stk.pop();
    stk.pop();
    stk.pop();

    return 0;
}