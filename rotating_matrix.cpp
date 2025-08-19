#include<iostream>
#include<vector>
using namespace std;


void rotate(vector<vector<int> >& mat) {
    // Your code goes here
    int n = mat[0].size();
    int m = mat.size();
    int x=n-1;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            // cout<<i<<"->"<<mat[i][j]<<","<<mat[x][n-1]<<endl;
            swap(mat[i][j],mat[x--][n-1]);
        }
        --n;
        x=m-1;
    }
    n =m;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            
        }
    }
}
int main() {
    vector<vector<int>> mat = {
        {1, 2, 3,10},
        {4, 5, 6,11},
        {7, 8, 9,12},
        {13,14,15,16}
    };
    rotate(mat);
    for(int i=0;i<mat[0].size();i++){
        for(int j=0;j<mat[0].size();j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}