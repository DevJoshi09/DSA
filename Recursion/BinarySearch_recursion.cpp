// binary search using recursion
#include<iostream>
using namespace std;
void print(int arr[],int start,int end){
    cout<<"searching between: "<<start<<" and "<< end<<endl;
    for(int i=start;i<=end;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void binary_search(int arr[],int start,int end,int target){

    print(arr,start,end);

    int mid= start + (end - start)/2;
    if(start>end){
        cout<<"not found";
        return ;
    }
    else if(arr[mid]== target) {
        cout<<endl;
        cout<<"index : "<<mid;
        return ;
    }else if(arr[mid]< target){
        start=mid+1;
        binary_search(arr,start, end, target);
    }else{
        end = mid -1;
        binary_search(arr,start, end, target);
    }
}
int main(){
    
    int arr[9]={1,2,3,4,5,6,7,8,9};
    binary_search(arr,0,8,0);

}