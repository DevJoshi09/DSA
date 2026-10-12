// Max Rectangle in a Matrix n,m
#include<bits/stdc++.h>
using namespace std;

class solution{
private:
    vector<int>prevSmallestElements(vector<int>v,int i,int m){
        // check minimum previous index
        stack<int>s;
        s.push(-1);
        // store minimum previous index 
        vector<int>arr(m);

        for(int i=0;i<m;i++){
            int curr = v[i];
            while(s.top() != -1 && v[s.top()] >= curr){
                s.pop();
            }
            arr[i] = s.top();
            s.push(i);
        }
        return arr;
    }
    vector<int>nextSmallestElements(vector<int>v,int i,int m){
        // check minimum next index
        stack<int>s;
        s.push(-1);
        // store minimum next index 
        vector<int>arr(m);

        for(int i=m-1;i>=0;i--){
            int curr = v[i];
            while(s.top() != -1 && v[s.top()] >= curr){
                s.pop();
            }
            arr[i] = s.top();
            s.push(i);
        }
        return arr;
    }
public:
    void maxRectangle(vector<vector<int>>matrix){
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> ans(m,0);
        vector<int>prev(m);
        vector<int>next(m);
        int max_area = INT_MIN;

        for(int i= 0;i<n;i++){

            for(int j=0;j<m;j++){
                if(matrix[i][j] != 0) ans[j] += matrix[i][j];
                else ans[j] = 0;
            }

            prev = prevSmallestElements(ans,i,m);
            next = nextSmallestElements(ans,i,m);

             
            for(int j=0;j<m;j++){

                if(next[j] == -1){
                    next[j] = m;
                }
                int l = ans[j];
                int b = next[j] - prev[j] - 1;

                int newArea = l * b;
                max_area = max(max_area,newArea);
            }
        }

        cout<<"Maximum Rectangle Area : "<< max_area;
    }

};
int main(){

    solution sol;
    vector<vector<int>> v = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

    sol.maxRectangle(v);
    return 0;
}