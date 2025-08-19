#include<iostream>
using namespace std;
/*
 //macro
#define pi 3.14
*/

// inline int getmax(int& a , int& b){
//     return (a>b)? a : b ;
// }

// default 
void print(int n, int start = 0){
    for(int i=start;i<=n;i++) cout<<i<<" ";
}
int main(){
    /*
    //macros
    int r=5;
    double area = pi * r * r;
    cout<<area<<endl;
    return 0;
    */
   /*
   //inline

    int a=1,b=2;
    //inline function call
    int maxi = getmax(a,b);

    cout<<maxi<<endl;
    */
   //
    int n=7,start;
    print(n,start);
}