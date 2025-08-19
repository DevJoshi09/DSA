// letter combination of phone no
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
void combination(string arr[],vector<string>& ans,string digit, string output){
     for(int i=0;i<digit.size()-1;i++){
        int num1 = digit[i] - '0';
        string s1 = arr[num1];
        for(int j=i+1;j<digit.size();j++){
            int num2 = digit[j] - '0';
            string s2 = arr[num2];
            for(int k=0;k<s1.size();k++){
                output.push_back(s1[k]);
                for(int l=0;l<s2.size();l++){
                    output.push_back(s2[l]);
                    ans.push_back(output);
                    output.pop_back();
                }
                output.pop_back();
            }
        }
    }
}
*/
void combination(string arr[],vector<string>& ans,string digit, string output, int index){
//    base condition 
    if(index >= digit.size()){
        ans.push_back(output);
        return ;
    } 

    int number = digit[index] - '0';
    string str = arr[number];

    // traverse the letter of digit
    for(int i=0;i<str.size();i++){
        output.push_back(str[i]);
        combination(arr,ans,digit,output,index+1);
        output.pop_back();
    }

}

int main(){

    string arr[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string digit="234";

    vector<string> ans={""};
    string output="";

    combination(arr,ans,digit,output);
    // combination(arr,ans,digit,output,0);

    for(auto i : ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}