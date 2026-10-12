// get Min element from the stack in O(1) time and space complexcity.
#include<bits/stdc++.h>
using namespace std;


class getMin{

int mini = INT_MAX;
int top = 0;
stack<int>s;

public:
   
    void gtMin(){
        cout<<mini<<endl;
    }

    void pushh(int curr){
        
        if(s.empty()){
            s.push(curr);
            mini = curr;
        }else if (curr < mini){
            int val = 2 * curr - mini;
            s.push(val);
            mini = curr;
        }else{
            s.push(curr);
        }
    }

    void popp(){
        if(s.empty()){
            cout<<"Stack is Empty."<<endl;
            return ;
        }
        int curr = s.top();
        if(curr > mini){
            s.pop();
        }else{
            int val = 2 * mini - curr;
            mini = val;
            s.pop();
        }
        cout<<"top->"<<curr<<endl;
    }
};
int main(){

    getMin get;
    get.pushh(-2);
    get.pushh(0);
    get.pushh(-3);
    // get.pushh(2);
    // get.pushh(7);

    get.gtMin();
    get.popp();
    get.gtMin();
    get.popp();
    get.gtMin();
    // get.popp();
    // get.gtMin();

    return 0;
}