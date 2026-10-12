// Largest Rectangular Area in Histogram 
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class solution{
private:
    vector<int>previousSmallestElement(vector<int>height,int n){
            // used for checking min element index
            stack<int>s;
            s.push(-1);
            // used to store previous minimum element index
            vector<int>ans(n);
            
            for(int i=0;i<n;i++){
                int curr = height[i];
                while(s.top() != -1 && height[s.top()] >= curr){
                    s.pop();
                }
                ans[i] = s.top();
                s.push(i);

            }
            return ans;
    }
    vector<int>nextSmallesElement(vector<int>height,int n){
            // used for checking min element index
            stack<int>s;
            s.push(-1);
            // used to store next minimum element index
            vector<int>ans(n);
            
            for(int i=n-1;i>= 0;i--){
                
                int curr = height[i];
                while(s.top() != -1 && height[s.top()] >= curr){
                    s.pop();
                }
                ans[i] = s.top();
                s.push(i);

            }
            return ans;
    }
        
public:
    void LargestRectangleArea(vector<int>height){
        
        int n = height.size();
        
        vector<int>prev(n);
        prev = previousSmallestElement(height,n);
        vector<int>next(n);
        next = nextSmallesElement(height,n);
        int area = INT8_MIN;

        for(int i=0;i<n;i++){

            if(next[i] == -1){
                next[i] = n;
            }
            int l = height[i];
            int b = next[i] - prev[i] - 1;

            int newArea = l * b;
            area = max(area,newArea);
        }

        cout<< "Largest Rectangular Area in Histrogram : "<<area;

    }
};
int main(){
    solution sol;
    vector<int>v = {2,1,5,6,2,3};

    sol.LargestRectangleArea(v);

    return 0;
}