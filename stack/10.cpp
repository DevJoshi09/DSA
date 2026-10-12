// Celebrity Problem - Check if there is any celebrity present in the party 
// celebrity is the person who knows no one , and everyone knows him.
#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class solution{
    public:

    int celebrityProblem(vector<vector<int>>v){
        stack<int>s;
        int n = v.size();

        for(int i=0;i<n;i++){
            s.push(i);
        }
        
        while(s.size() != 1){
            int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();

            // if y knows x
            if(v[x][y] == 0 && v[y][x] == 1){
                s.push(x);
                
            }//if x knows y
            else if(v[x][y] == 1 && v[y][x] == 0){
                s.push(y);
            }
        }
        int potential_candidate = s.top();
        // verify 

        for(int i=0;i<n;i++){

            if(i == potential_candidate) continue;

            // celebrity knows no one -> check all row is 0 or not
            if(v[potential_candidate][i] == 1) return -1;

            // everyone knows celebrity

            if(v[i][potential_candidate] == 0){
                return -1;
            }
        }
        for(int i= 0;i<n;i++){
            
        }
        return potential_candidate;
    }
};
int main(){
    solution sol;
    vector<vector<int>>v={{0,1,1},{0,0,1},{0,0,0}};
    int ans = sol.celebrityProblem(v);

    if(ans >= 0) cout<<"Celebrity : "<<ans;
    else cout<< "No celebrity ";

    return 0;
}