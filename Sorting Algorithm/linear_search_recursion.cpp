//linear search using recursion
#include<iostream>
using namespace std;
void print(int arr[],int i,int n){
    cout<<"searching "<<endl;
    for(int j=i;j<n;j++){
        cout<<arr[j]<<" ";
    }
    cout<<endl;
}
bool search(int arr[] , int x,int i,int n){
    // show search flow 
    print(arr,i,n);
    //base case
    if(i == n) return 0;

    if(arr[i]== x) return 1;

    // recurance relation 
    return search(arr,x,++i,n);
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

    cout<<(search(arr,x,0,n)?"element found" : "element not found");

}