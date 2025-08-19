// count no of distinct way to climb 0th to N th floor . can take 1 or 2 step at a time. {by resursion}
#include<iostream>
using namespace std;

int distinct(int n){
    // base condition
    if(n<0) return 0;
    if(n==0 || n==1) return 1;
    // recursive condition
    return (distinct(n-1) + distinct(n-2));
}
int main(){
    int n=5;
    int count= distinct(n);
    for(int i=0;i<n;i++){
        cout<<distinct(i)<<" ";
    }
}
// not fully optimized