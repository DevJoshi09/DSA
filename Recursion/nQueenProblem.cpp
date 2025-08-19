#include<iostream>
#include<vector>
using namespace std;

void visit(vector<vector<int>>& chess_board, int y, int x, int n, int t){
    // for x and y axis
        for(int i=0;i<n;i++){
            chess_board[y][i]+=t;
            chess_board[i][x]+=t;
        }
    // for main diagonal
        // for down right
            int i=y,j=x;
            while(i<n && j<n){
                chess_board[i++][j++]+=t;
            }
        // for up left
            i=y;j=x;
            while(i>=0 && j>=0){
                chess_board[i--][j--]+=t;
            }
    // for anti diagonal
        // for down left
            i=y;j=x;
            while(i<n && j>=0){
                chess_board[i++][j--]+=t;
            }
        // for up right
            i=y;j=x;
            while(i>=0 && j<n){
                chess_board[i--][j++]+=t;
            }
}
void solve(vector<vector<int>>& chess_board, vector<vector<int>>& ans, vector<int>& placed, int n,int y){
    //  base case
    if( y>=n && placed.size()==n){
        ans.push_back(placed);
        return ;
    }

    for(int i=0;i<n;i++){

        if(chess_board[i][y]==0){
            visit(chess_board,i,y,n,1);
            placed.push_back(i+1);
            // recursion call
            solve(chess_board,ans,placed,n,y+1);
            // backtrack
            placed.pop_back();
            visit(chess_board,i,y,n,-1);
        }
    }
}


vector<vector<int>> nQueen(int n){
    vector<vector<int>> chess_board(n,vector<int>(n,0));
    vector<int>placed;
    vector<vector<int>>ans;
    solve(chess_board,ans,placed,n,0);
    return ans;
}
int main(){
    int n=5;
    vector<vector<int>>ans = nQueen(n);
    int i=0;
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;

}