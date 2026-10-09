// Insert element at the bottom of stack
#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>&stk, int n){
    // base case
    if(stk.empty()){
        stk.push(n);
        return ;
    }

    int temp = stk.top();
    stk.pop();

    insertAtBottom(stk,n);

    stk.push(temp);
}
int main(){
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    int num = 9;
    insertAtBottom(s,num);

    while(!s.empty()){
        
        cout<<'|' << s.top() <<'|'<<endl;
        cout<<" \n---\n";
        s.pop();
    }
    return 0;
}