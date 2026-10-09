// Delete middle element from stack
#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>&stk, int count, int size){
    // base case
    if(size/2 == count){
        stk.pop();
        return ;
    }

    int num = stk.top();
    stk.pop();

    // recursive call
    solve(stk,count + 1,size);

    // putting back all elements
    stk.push(num);
}
void deleteMiddle(stack<int>&s){
    int count = 0;
    int n = s.size();
    solve(s,count,n);

    while(!s.empty()){
        cout<<s.top()<<" | ";
        s.pop();
    }
}

int main(){

    stack<int>s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    deleteMiddle(s);
    return 0;
}