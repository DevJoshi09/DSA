//Recursion
#include<iostream>
using namespace std;

int factorial(int n){

    // base case 
    if(n==1 || n==0) return 1;

    // recurrance relation
    int ans = n * factorial(n-1);

    return ans;
    /* can also be writen as 

        return n * factorial(n-1);
    */
}
// power of 2
int power(int n){
    // base case
    if(n==0) return 1;

    // rr
    return 2 * power(n-1);
}

// print counting

void print(int n){
    
    // base case
    if(n<0) return ;

    // processing case for end rr
    cout<<n<<" ";

    // recursion relation
    print(n-1);

    // processing case for head rr
    //cout<<n<<" ";

}
int main(){
    // find factorial

    int n=3;
    cout<<"factorial of n : "<<factorial(n)<<endl;
    
    cout<<"power of Two :"<<power(n)<<endl;

    cout<<"print counting in decreasing order : ";
    print(n);
    cout<<endl;

}