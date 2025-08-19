//pallindrome using recursion
#include<iostream>
using namespace std;

bool check(string s,int i, int j){
    // base case
    
    // checked all index
    if(i==j || i>j) return 1;
    //not equal 
    if(s[i]!=s[j]) return 0;

    // recurance relation
    return check(s,i+1,j-1);
}

int main(){
    string s="acba";

    cout<<(check(s,0,3)?"Palindrome":"Not a Palindrome");
}