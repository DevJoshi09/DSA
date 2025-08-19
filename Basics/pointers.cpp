#include<iostream>

using namespace std;

void update_address(int *ptr){
    ptr=ptr+1;
    cout<<"addr. of ptr inside :"<<ptr<<endl;
}
void update_value(int *ptr){
    *ptr+=1;
}
int main(){
    // int num=5;

    // int *ptr = &num;

    // cout<<*ptr<<" - "<<ptr<<endl;

    // *ptr+=1;
    // cout<<ptr<<endl;

    // int *q = ptr;
    // *q=*q +1;
    // cout<<num<<" - "<<*ptr<<" - "<<*q<<endl;

    // int arr[10];
    // cout<<"address of 0 th location of array"<<endl;
    // cout<<arr<<" "<<&arr[0]<<endl;
    // int *ptr = &arr[0];//&arr[0]
    // cout<<"addr of pointer and value"<<endl;
    // cout<<ptr<<" "<<*ptr<<endl;

    // //size of arr adress and pointer
    // cout<<sizeof(arr)<<" "<<sizeof(&ptr)<<" "<<sizeof(*ptr)<<" "<<sizeof(ptr)<<endl;
    // char ch[6]="abcdf";
    // //implementation is different from array
    // cout<<&ch[0]<<endl;
    // char  *c=&ch[0];
    // cout<<*c<<endl;
    int arr[]={2,5,1,4,3};
    int *ptr=arr;
    cout<<"ptr address before :"<<ptr<<endl;
    update_address(ptr);
    // no changes
    cout<<"ptr adress after :"<<ptr;

    cout<<endl<<endl;
    // values can be changed
    cout<<"value before "<<*ptr<<endl;
    update_value(ptr);
    cout<<"value after :"<<*ptr<<endl;

    cout<<endl<<endl;
    // double pointer
    int i=5;
    int *p=&i;
    int* *p2=&p;
    int** *p3=&p2;
    cout<<&i<<" "<<p<<" "<<p2<<" "<<p3<<endl;
    //all pointing to i value
    cout<<i<<" "<<*p<<" "<<**p2<<" "<<***p3<<endl;
    // all pointing to i address
    cout<<" "<<p<<" "<<*p2<<" "<<**p3<<endl;
    cout<<i<<" "<<p<<" "<<p2<<" "<<p3<<endl;
    cout<<*p3<<**p3;
}
