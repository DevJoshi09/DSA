// Reverse stack using Recursion 
#include<iostream>
#include<stack>
using namespace std;

void InsertAtBottom(stack<int>&s, int num){
    // base case
    if(s.empty()){
        s.push(num);
        return;
    }

    int top = s.top();
    s.pop();
    InsertAtBottom(s,num);

    s.push(top);
}

void ReverseStack(stack<int>&s){
    // base case
    if(s.empty()){
        return ;
    }

    int top = s.top();
    s.pop();

    // recursive call
    ReverseStack(s);

    InsertAtBottom(s,top);
}

int main(){

    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    while(!s.empty()){
        cout<< s.top()<< endl;
        s.pop();
    }
    cout<<"---------\n";
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    ReverseStack(s);

    while(!s.empty()){
        cout<< s.top()<< endl;
        s.pop();
    }
    return 0;

}