// //merge sort
// #include<iostream>
// using namespace std;

// void merge(int* arr, int s, int e){

//     int mid = (s+e)/2;

//     int len1 = mid - s + 1;
//     int len2 = e - mid;

//     int main_index=s;

//     int *first = new int [len1];
//     int *second = new int [len2];

//     // insert element in temporary array
//     for(int i=0;i<len1;i++){
//         first[i]=arr[main_index++];
//     }
//     main_index = mid + 1;
//     for(int i=0;i<len2;i++){
//         second[i]=arr[main_index++];
//     }

//     //index of first array 
//     int index1=0;
//     // index of second array
//     int index2=0;
//     //main index 
//     main_index=s;
//     // merge and sort
//     while(index1 < len1 && index2 < len2){

//         if(first[index1] < second[index2]){

//             arr[main_index++]=first[index1++];

//         }else{
//         // if(first[index1] > second[index2]){
//             arr[main_index++]=second[index2++];
//         }
//     }
//     while(index1 < len1){
//         arr[main_index++]=first[index1++];
//     }
//     while(index2 < len2){
//         arr[main_index++]=second[index2++];
//     }
//     // remove mannually from heap
//     delete []first;
//     delete []second;
// }

// // merge sort

// void merge_sort(int* arr, int s, int e){
//     //base case
//     if(s>=e){
//         return ;
//     }
//     int mid=(s+e)/2;
//     // divide
//     //left-> side
//     merge_sort(arr,s,mid);
//     //right->side
//     merge_sort(arr,mid+1,e);

//     // concure
//     merge(arr,s,e);

// }

// int main(){
//     int arr[10]={2,3,4,1,7,9,8,6,5,10};

//     merge_sort(arr,0,9);
//     for (int i = 0; i < 10; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
    
// }

#include<iostream>
using namespace std;

// merge nodes
void merge_nodes(int* arr, int s, int e){
    
    int mid = (e + s)/2;
    
    // length of left and right half
    int len1 = mid - s + 1;
    int len2 = e - mid;

    // storing left and right half in array
    int *first = new int [len1];
    int *second = new int [len2];

    int idx = s;
    for(int i=0;i<len1;i++){
        first[i] = arr[idx++];
    }

    for(int i=0;i<len2;i++){
        second[i] = arr[idx++];
    }
    
    // compare elements of both array and sortedly insert in original array 
    idx = s;
    int idx1 = 0, idx2 = 0;
    while(idx1 < len1 || idx2 < len2){

        // special condition for checking first array out of bound
        if(idx1 >= len1 && idx2 < len2){
            
            arr[idx++] = second[idx2++];
            continue;
        }
        // special condition for checking second array out of bound
        if(idx2 >= len2 && idx1 < len1){

            arr[idx++] = first[idx1++];
            continue;
        }

        // check for small element and insert it 
        if(first[idx1] < second[idx2]){

            arr[idx++] = first[idx1++];
        }else{
            arr[idx++] = second[idx2++];
        }
    }

    delete []first;
    delete []second;

}

void merge_sort(int *arr, int s, int e){
    // base case
    if(s>=e){
        return ;
    }
    int mid = (e + s)/2;
    // divide array into small node
    // step 1: left->side of mid
    merge_sort(arr, s, mid);
    
    // step 2: right->side of mid
    merge_sort(arr, mid+1, e);

    // now merge all nodes , left -> right 
    merge_nodes(arr, s, e);
}

int main(){
    int n ;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    merge_sort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}