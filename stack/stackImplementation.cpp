#include<iostream>
using namespace std;

class stack{
  private:

    int Top = -1;
    // array has to be dynamically allocated
    int* arr;
    int size;

  public:
    stack(int size){
        this->size = size;
        arr = new int [size];
        Top = -1;
    }
    void push(int val){

         if(Top < size - 1){
            Top++;
            arr[Top] = val;
        }else{
            cout<<"\nstack over flow...\n";
        }
    }

    void pop(){
        if(Top >= 0){
            Top--;
        }else{
            cout<<"\n stack is under flow...\n";
        }
    }

    int top(){
        if(Top != -1){
            return arr[Top];
        }
        return -1;
    }

    bool Empty(){
        
        return Top == -1;
    }
};

int main(){

    cout<<"enter the size of stack : ";
    int n;
    cin>>n;

    stack s(n);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout<<s.top()<<endl;
    
    s.pop();
    cout<<s.top()<<endl;

    s.pop();
    cout<<s.top()<<endl;

    s.pop();
    cout<<s.top()<<endl;

    s.pop();

    if(s.Empty()){
        cout<<"Stack is empty \n";
    }
   return 0;
}