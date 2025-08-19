#include<iostream>
using namespace std;

int partition(int arr[],int s,int e){

    int pivot = arr[s];
    int count=0,i=s+1;
    while(i<=e){
        if(arr[i]<=pivot) count++;

        i++;
    }
    //cout<<pivot<<" ";
    int index = s+count;
    swap(arr[s],arr[index]);

    i=s;
    int j=e;
    while(i<index && j>index){

        while(arr[i]<pivot){
            i++;
        }
        while (arr[j]>pivot)
        {
            j--;
        }
        if(i<index && j>index){
            cout<<arr[i]<<" "<<arr[j]<<endl;
            swap(arr[i++],arr[j--]);

        }

    }

    return index;
}
void quicksort(int arr[] , int s , int e){

    // base case
    if(s>=e) return ;

    //partition
    int p = partition(arr,s,e);

    //recurance relation
    // left partition 
    quicksort(arr,s,p-1);
    // right partition
    quicksort(arr,p+1,e);
}
int main(){
    int arr[5]={5,4,3,2,1};

    quicksort(arr,0,4);
    for(auto it : arr){
        cout<<it<<" ";
    }
    cout<<endl;
}