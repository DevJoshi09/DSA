//linear search using recursion
#include<iostream>
using namespace std;

bool search(int* arr , int x,int i){
    //base case
    if(i == *arr.size()) return 0;

    if(arr[i]== x) return 1;

    // recurance relation 
    return search(arr,x,--i);
}
int main(){
    int n,x;
    cout<<"enter size of array: ";
    cin>>n;
    
    int *arr = new int [n];
    for(int i=0;i<n;++i){
        cin>>*(arr+i);
    }
    cout<<endl<<"target : ";
    cin>>x;
    cout<<endl;

    if(search(arr,x,0))? cout<<"element found"; : cout<<"element not found";

}