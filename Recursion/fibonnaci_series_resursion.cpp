// fibonacci series implementation with recursion
#include<iostream>
using namespace std;

int f(int n){

    //base condition
    if(n==0) return 0;
    //base condition
    if(n==1 || n==2) return 1;

    // recurance relation 
    return (f(n-1)+f(n-2));
    
}
int main(){

    int n=15;
    while(n--) cout<<f(n)<<" ";

}