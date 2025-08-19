//say digit -> given an number write into words 1->"one",12-> "one two"
#include<bits/stdc++.h>
using namespace std;

string word(vector<string> arr, int n,string s){
    //base case
    if(n==0) return "";

    //processing
    //int i=n%10;
    //n=n/10;

    // recurance relation
    s= word(arr,n/10,s) +" ";
    //processing
    int i=n%10;
    s+= arr[i] + " ";
    return s;

}

int main(){
    int n=413;
    vector<string> arr={"zero","one","two","three","four","five","six","seven","eight","nine"};
    string s=" ";

    cout<<word(arr,n,s);
    //cout<<s;
}