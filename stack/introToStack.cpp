#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int>s;
    cout<<"No. of elements to be inserted : ";
    int n,val;
    cin>>n;
    int* arr = new int[n];
    cout<<" enter elements : ";

    // push operation
    for(int i=0;i<n;i++){
        cin>>val;
        arr[i]=val;
        s.push(val);
    }
    for(int i=0;i<n;i++){
        cout<<"| "<<arr[i]<<" |"<<endl;
        cout<<" ---"<<endl;        
    }
    
    // pop operation
    s.pop();

    // top element
    // cout<<s.top()<<endl;

    // check empty
    if (s.empty())
        cout << "empty";
    else
        cout << "not empty";


}