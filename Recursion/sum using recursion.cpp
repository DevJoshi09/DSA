// sum of an array using recursion

#include<iostream>
using namespace std;

int sum_of_array(int* arr, int n){
    //base case
    if(n==0) return arr[0];
    // recurance relation
    int sum = sum_of_array(arr,n-1) + arr[n];
    return sum;
}
int main(){
    int n;
    cout<<"enter size of array: ";
    cin>>n;
    int *arr = new int [n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum = sum_of_array(arr,n-1);
    cout<<sum;
    return 0;
    
}