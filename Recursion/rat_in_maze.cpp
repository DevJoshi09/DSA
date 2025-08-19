// Rat in Maze Problem - calculate the no of way to reach destination(n-1,m-1) from start(0,0)
#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isSafe(int x, int y, vector<vector<int>>visited, vector<vector<int>> matrix){
    if((x>=0 && x<matrix.size()) && (y>=0 && y<matrix.size()) && visited[x][y]==0 && matrix[x][y]==1){
        return true;
    }
    return false;
}

void helper(vector<vector<int>> matrix,vector<string>& ans,vector<vector<int>>visited,string path,int i,int j){
    // you have reached
    // base case
    if(i == matrix.size()-1 && j==matrix.size()-1){
        ans.push_back(path);
        return ;
    }
    visited[i][j]=1;
    //recurance relation-D,L,R,U
    //Down
    int newx = i+1;
    int newy = j;
    if(isSafe(newx,newy,visited,matrix)){
        path.push_back('D');
        helper(matrix,ans,visited,path,newx,newy);
        path.pop_back();
    }
    // Left
    newx = i;
    newy = j-1;
    if(isSafe(newx,newy,visited,matrix)){
        path.push_back('L');
        helper(matrix,ans,visited,path,newx,newy);
        path.pop_back();
    }
    //RIGHT
    newx = i;
    newy = j+1;
    if(isSafe(newx,newy,visited,matrix)){
        path.push_back('R');
        helper(matrix,ans,visited,path,newx,newy);
        path.pop_back();
    }
    //UP
    newx = i-1;
    newy = j;
    if(isSafe(newx,newy,visited,matrix)){
        path.push_back('U');
        helper(matrix,ans,visited,path,newx,newy);
        path.pop_back();
    }

    visited[i][j]=0;
}

vector<string> ratInMaze(vector<vector<int>>& matrix){
     vector<string>ans;
     vector<vector<int>>visited = matrix;
     for(int i=0;i<visited.size();i++){
        for(int j=0;j<visited.size();j++)
            visited[i][j]=0;
     }
     string path="";

     helper(matrix,ans,visited,path,0,0);
     return ans;
}


int main(){
    vector<vector<int>>matrix = {{1,1,1,0},
                {1,1,1,1},
                {1,0,0,0},
                {0,0,1,1}
    };

    vector<string>ans = ratInMaze(matrix);

    for(auto s:ans){
        cout<<s<<" ";
    }
    cout<<endl;

    return 0;

}