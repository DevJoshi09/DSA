// permutation of a string 
// lexicographical order
#include<iostream>
#include<vector>
#include<string>
using namespace std;

void permutation(string s, vector<string>&ans, int index){
    // base case
    if(index >= s.size()){
        ans.push_back(s);
        return ;
    }

    for(int j=index;j<s.size();j++){
        swap(s[index],s[j]);
        // recursion
        permutation(s,ans,index+1);

        //  backtrack
        swap(s[index],s[j]);
    }
}

int main(){
    string s="abc";
    vector<string>ans;
    permutation(s,ans,0);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}