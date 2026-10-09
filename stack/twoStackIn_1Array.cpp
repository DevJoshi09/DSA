#include<iostream>

using namespace std;

class stk{
    private:
        int size;
        int top1=-1;
        int top2;
        int *arr;
    
    public:
        stk(int size){
            this->size = size;
            top2=size;
            arr = new int[size];
        }
        // push in stack 1
        void push1(int data){
            // this condition will check for space left in array or not
            if(top2 - top1 > 1){    
                top1++;
                arr[top1] = data;
                
            }else{
                cout<<"stack 1 overflow..."<<endl;
            }
        }
        // push in stack 2
        void push2(int data){
            
            if(top2 - top1 > 1){
                top2--;
                arr[top2] = data;
                
            }else{
                cout<<"stack 2 overflow..."<<endl;
            }
        }

        // pop in stack 1
        void pop1(){
            if(top1 <= 0){
                cout<<"Stack 1 underflow..."<<endl;
            }else{
                top1--;
            }
        }
        // pop in stack 2
        void pop2(){
            if(top2 == size){
                cout<<"Stack 2 underflow..."<<endl;
            }else{
                top2++;
            }
        }
        // print
        void print() {
        cout << "\n1st Stack elements:\n"<<endl;
        if (top1 >= 0) {
            for (int i = top1; i >= 0; i--) {
                cout << "| " << arr[i] << " |" << endl;
            }
            cout << " ---" << endl;
        } else {
            cout << "(Empty)\n";
        }

        cout << "\n2nd Stack elements:\n"<<endl;
        if (top2 < size) {
            for (int i = top2; i < size; i++) {
                cout << "| " << arr[i] << " |" << endl;
            }
            cout << " ---" << endl;
        } else {
            cout << "(Empty)\n";
        }
        cout << endl;
    }
};

int main(){
    // int n;
    // cout<<"Enter size of  array :";
    // cin>>n;

    

    // stk.push1(1);
    // stk.push2(3);
    // stk.push2(4);
    // stk.push1(2);

    // stk.print();
    int n;
    cout<<"enter size of array :";
    cin>>n;
    stk stk(n);
    bool flag = true;
    
    while(flag == true){
        int option;
        
        cout<<"1. push in stack 1"<<endl;
        cout<<"2. push in stack 2"<<endl;
        cout<<"3. pop in stack 1"<<endl;
        cout<<"4. pop in stack 2"<<endl;
        cout<<"5. print..."<<endl;
        cout<<"6. Exit..."<<endl;
        cout<<"Choose your options :";
        cin>>option;
        cout<<endl;
        // stk(5);
        switch (option)
        {
        case 1:
            int data;
            cout<<"Enter data :";
            cin>>data;
            stk.push1(data);
            break;
        
        case 2:

            cout<<"Enter data :";
            cin>>data;
            stk.push2(data);
            break;

        case 3:
            stk.pop1();
            break;
        
        case 4:
            stk.pop2();
            break;

        case 5:
            stk.print();
            break;

        default:
            flag = false;
            break;
        }
    }
    

    return 0;
} 