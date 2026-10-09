// Check Valid Paranthesis 
#include<iostream>
#include<stack>
using namespace  std;

bool match(char top , char ch){
    if((top=='(' && ch==')') || (top=='{' && ch=='}') || (top=='[' && ch==']')){
        return true;
    }
    return false;
}

bool validation(string paran){
    stack<char> s;
    int n = paran.size();

    for(int i = 0; i<n; i++){
        char ch = paran[i];

        if(ch=='(' || ch=='{' || ch=='['){
            s.push(ch);
            continue;
        }

        if(!s.empty()){
            char top = s.top();
            if(match(top,ch)){
                s.pop();
            }else {
                return false;
            }
        }else{
            return false;
        }
    }
    if(s.empty()) return true;

    return false;
}
int main(){

    string paranthesis = "[{[()]}]]";

    bool ans = validation(paranthesis);
    if(ans) cout<<"paranthesis are in correct format";
    else cout<<"Invalid format";
    return 0;
}
