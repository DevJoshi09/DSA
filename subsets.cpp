#include<iostream>
#include<string>
#include<vector>
using namespace std;
//sliding window concept

// void subsets(string str , vector<string>& s){
//     int n = str.size();
//     string temp_s=" ";
//     for(int i=0;i<n;i++){
//         temp_s = str[i];
//         s.push_back(temp_s);
//         for(int j=i+1;j<n;j++){
//             temp_s += str[j];
//             s.push_back(temp_s);
//         }
//     }
// }

// using tail recursion
void subsets (string str , vector<string>& s ,string temp_s , int i){
    //base case 
    if(i>=str.size()) return ;

    //processing case
    temp_s += str[i];
    s.push_back(temp_s);

    //recursion relation
    subsets(str,s,temp_s,i+1);
    
}

int main(){

    string str = "abc";
    vector<string>s={""};
    for(int i=0;i<str.size();i++){
        string temp_s = " ";
        subsets(str,s,temp_s,i);

    }
    

    for(auto i=0;i<s.size();i++){
        cout<<s[i]<<" ";
    }

    return 0;
}