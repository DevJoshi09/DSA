// N stack in an array
#include<bits/stdc++.h>
using namespace std;

class nStack{
    int *arr;
    int *top;
    int *next;

    int n, k;
    int freespot;

public:
    nStack(int N, int S){
        // size of array
        n = N;
        // no of stack
        k = S;
        arr = new int[n];
        top = new int[k];
        next = new int[n];

        // initialize top
        for(int i=0;i<k;i++){
            top[i] = -1;
        }

        // initialize next
        for(int i=0;i<n;i++){
            next[i] = i+1;
        }

        // update last element index -1
        next[n-1] = -1;
        // initialize free spot
        freespot = 0;

    }
    // push x into mth stack. return -1 if space is not empty
    void push(int x, int m){

        // check freespace
        if(-1 == freespot){
            cout<<"\n NO free Space"<<endl;
            return ;
        }

        // find index
        int index = freespot;
        // freespot update
        freespot = next[index];
        // insert in array
        arr[index] = x;
        // update next 
        next[index] = top[m-1];
        // update top
        top[m - 1] = index;

    }

    // pop element from mth stack . return -1 if stack is empty .
    void pop(int m){

        if(top[m-1] == -1){
            cout << "Stack Underflow"<<endl;
        }

        int index = top[m - 1];
        top[m-1] = next[index];
        next[index] = freespot;
        freespot = index;

        cout<< arr[index]<<endl;
    }
};

int main(){
    int n,k;

    nStack stk(5,3);
    // array size = 5, no of stack = 3

    stk.push(10,1);
    stk.push(20,2);
    stk.push(30,1);
    stk.push(40,3);
    stk.push(50,2);

    stk.pop(1);
    stk.pop(2);
    
    stk.push(30,1);
    stk.push(40,3);
    stk.push(50,2);

    stk.pop(1);
    stk.pop(2);


    return 0;
}