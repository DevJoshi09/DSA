//merge sort
#include<iostream>
using namespace std;

void merge(int* arr, int s, int e){

    int mid = (s+e)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int main_index=s;

    int *first = new int [len1];
    int *second = new int [len2];

    // insert element in temporary array
    for(int i=0;i<len1;i++){
        first[i]=arr[main_index++];
    }
    main_index = mid + 1;
    for(int i=0;i<len2;i++){
        second[i]=arr[main_index++];
    }

    //index of first array 
    int index1=0;
    // index of second array
    int index2=0;
    //main index 
    main_index=s;
    // merge and sort
    while(index1 < len1 && index2 < len2){
        if(first[index1] < second[index2]){
            arr[main_index++]=first[index1++];
        }
        if(first[index1] > second[index2]){
            arr[main_index++]=second[index2++];
        }
    }
    while(index1 < len1){
        arr[main_index++]=first[index1++];
    }
    while(index2 < len2){
        arr[main_index++]=second[index2++];
    }
    // remove mannually from heap
    delete []first;
    delete []second;
}

void merge_sort(int* arr, int s, int e){
    
    //base case
    if(s>=e){
        return ;
    }
    int mid=(s+e)/2;
    // divide
    //left-> side
    merge_sort(arr,s,mid);
    //right->side
    merge_sort(arr,mid+1,e);

    // concure
    merge(arr,s,e);

}

int main(){
    int arr[10]={2,3,4,1,7,9,8,6,5,10};

    merge_sort(arr,0,9);
    for (int i = 0; i < 10; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}