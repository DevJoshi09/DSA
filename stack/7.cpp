// Redundant Brackets
#include<iostream>
#include<stack>
using namespace std;

bool findRedundantBracket(string s){
    stack<char> stk;

    for(int i=0;i<s.length();i++){

        char c = s[i];
        cout<< c << endl;
        if(c == '(' || c == '+' || c == '-' || c == '*' || c == '/'){
            stk.push(c);

        }else if(c == ')'){
            bool isRedundant = true;

            while(!stk.empty() || stk.top() != '('){
                char temp = stk.top();
                if(temp == '+' || temp == '-' || temp == '*' || temp == '/'){
                    isRedundant = false;

                }else break;

                stk.pop();
            }

            if(isRedundant == true){
                return true;
            }
            stk.pop();
        }
    }
    return false;

}
int main(){
    string s = "(a+b)";
    bool ans = findRedundantBracket(s);

    if(ans == true) cout<<"redundant";
    else cout<<" Not redundant";
    return 0;
}