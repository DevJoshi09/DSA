//reverse a string using recursion
#include<iostream>
#include<string>
using namespace std;

void print(string s,int left, int right){
    cout<<s<<endl;
    cout<<"swap : "<<s[left]<<" "<<s[right]<<endl;
}

// double pointer approach
void reverse(string& s,int left, int right){
    print(s,left,right);
    //base case
    if(left == right || left > right) return ;
    swap(s[left],s[right]);
    //recurance relation
    reverse(s , left+1 , right-1);
}

// single pointer approach
void reverse2(string& s, int i){
    int j=s.size()-i-1;
    // base case

    if(i>j || i==j) return ;
    swap(s[i],s[j]);

    //recurance relation
    reverse2(s,i+1);
}

int main(){
    string s="abcde";
    reverse(s,0,4);
    cout<<s;
    cout<<endl;
    reverse2(s,0);
    cout<<s;
    return 0;
}
