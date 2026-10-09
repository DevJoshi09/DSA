// Next smaller element 
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

void print(vector<int>ans){
    cout<<" | "; 
    for(auto x : ans){
        cout<< x<<" | ";
    }
}

void nextSmallerElement(vector<int>v){
    int n = v.size();
    vector<int>ans;
    stack<int>s;
    s.push(-1);
    for(int i = n-1; i >= 0; i--){
        int temp = v[i];
        while(!s.empty()){
            if(s.top() < temp){
                ans.push_back(s.top());
                s.push(temp);
                break;
            }
            s.pop();
        }
    }
        reverse(ans.begin(),ans.end());

    print(ans);
}

int main(){

    vector<int>v= {2,1,4,3};

    nextSmallerElement(v);
    return 0;

}