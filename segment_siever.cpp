//segmented sieve
#include<bits/stdc++.h>

using namespace std;

long long helper(long long l, long long r){
    vector<bool>prime(r-l+1, true);
    long long count=0;
    for(int i=l;i<r;i++){
        if( i != 3 && i != 5 && i != 7 && i != 2)
        {    
            if(i%2 == 0){
                for(int j=i;j<r;j+=2){
                    long long t=j-l;
                    prime[t]=false;
                    //cout<<j<<" ";
                }
                //cout<<endl;
            }else if(i%3 == 0){
                for(int j=i;j<r;j=j+3){
                    long long t=j-l;
                    prime[t]=false;
                    //cout<<j<<" ";
                }
                //cout<<endl;
            }else if(i%5 == 0){
                for(int j=i;j<r;j=j+5){
                    long long t=j-l;
                    prime[t]=false;
                    //cout<<j<<" ";
                }
                //cout<<endl;
            }else if(i%7 == 0){
                for(int j=i;j<r;j=j+7){
                    long long t=j-l;
                    prime[t]=false;
                    //cout<<j<<" ";
                }
                //cout<<endl;
            }else {count++;
                cout<<i<<" ";
            }
        }else count++;
    }
    cout<<endl;
    return count;
        
}
int main(){
    long long l,r;
    cout<<"enter left index and right index: ";
    cin>>l>>r;

    long long count = helper(l,r);
    if(l<=1) count--;
    
    
    cout<<count;
}
