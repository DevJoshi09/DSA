#include<iostream>
#include<stack>
using namespace std;

int main(){

    string str = "dev";
    stack<char>s;
    for(int i=0; i<str.length(); i++){
        s.push(str[i]);
    }

    string ans = "";

    
    while(!s.empty()){
        char c = s.top();
        ans.push_back(c);
        s.pop();
    }

    cout<<"answer is :"<<ans;

    return 0;

}