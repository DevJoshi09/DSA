//dynamic array 
#include<bits/stdc++.h>
using namespace std;

int main(){

    // 1D array 
    int row;
    cout<<"input row: ";
    cin>>row;
    //int *arr = new int[n];

    // // arr[i] -> *(arr + i)
    // for(int i=0;i<n;i++) cin>>*(arr+i);
    // cout<<endl;
    // for(int i=0;i<n;i++) cout<<arr[i]<<" ";

    cout<<endl;

    // 2D array 

    int col;
    cout<<"input col :";
    cin>>col;//no of rows

    int **arr = new int*[row];

    // creation 
    for(int i=0;i<row;i++){
        //arr[i]->*(arr+i)
        *(arr + i)=new int[col];
    }
    cout<<endl;
    //input
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }
    cout<<endl;
    // output
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<sizeof(arr[0])<<endl;

    // release memory 
    for(int i=0;i<row;i++){
        delete []arr[i];
    }

    delete []arr;

    // Jaggered array -> row of different size
    //  int k;
    // int *temp = new int[row];
    // // creation 
    // for(int i=0;i<row;i++){
    //     cout<<"enter k: ";
    //     cin>>k;//width of every row
    //     temp[i]=k;
    //     //arr[i]->*(arr+i)
    //     *(arr + i)=new int[k];
    // }
    // cout<<endl<<"input 2D array"<<endl;
    // //input
    // for(int i=0;i<row;i++){
    //     for(int j=0;j<temp[i];j++){

    //         cin>>arr[i][j];
    //     }
    // }
    // cout<<endl;
    // // output
    // for(int i=0;i<row;i++){
    //     for(int j=0;j<temp[i];j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return 0;
}