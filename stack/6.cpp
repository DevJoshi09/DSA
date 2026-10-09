// Sort Stack without using a loop 
#include<iostream>
#include<stack>
using namespace std;

void SortingInsert(stack<int>&s, int num){
    if(s.empty() || s.top() > num){
        s.push(num);
        return;
    }

    int top = s.top();
    s.pop();
    // recussive call
    SortingInsert(s,num);
    
    s.push(top);

}

void SortStack(stack<int>&s){
    // base case
    if(s.empty()){
        return ;
    }

    int top = s.top();
    s.pop();

    SortStack(s);

    SortingInsert(s,top);
}


int main(){

    stack<int>s;
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    SortStack(s);

    while(!s.empty()){
        cout<< s.top()<< endl;
        s.pop();
    }

    return 0;
}