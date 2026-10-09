//  Convert a Non valid expression to a valid expression {} . Return the to make it Valid expression

# include<iostream>
#include<stack>
using namespace std;

int convetToValidExp(string s){
    int n = s.size();
    if(n % 2 != 0) return -1;

    stack<char> stk;
    int count = 0;

    for(int i = 0;i<n;i++){
        char c = s[i];
        if(c=='{') stk.push('{');
        else if(c == '}' && stk.top() == '{') stk.pop();
        else if(c == '}' && stk.empty()) {
            count++;
            stk.push('}');
        }
    }

    char temp ;
    while(!stk.empty()){
        temp = stk.top();
        stk.pop();
        if(stk.top() =='{' && temp == '{'){
            stk.pop();
            count++;
        }
    }
    return count;
}
int main(){

    string s = "{{{}}{{}}{";

    int ans = convetToValidExp(s);

    cout<< "Cost for Valid Expression : "<<ans;

    return 0;
}