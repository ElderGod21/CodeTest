#include <iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter the total amount: ";
    cin>>n;
    cout<<endl;

    int note100, note50, note20, note1;


    switch (n/100){
        case (0): note100 =0;
                   break;
        default: note100 = n/100;
                 n = n-note100*100;
                 break;
    }
     switch (n/50){
        case (0): note50 =0;
                   break;
        default: note50 = n/50;
                 n = n-note50*50;
                 break;
    }
     switch (n/20){
        case (0): note20 =0;
                   break;
        default: note20 = n/20;
                 n = n-note20*20;
                 break;
    }
     switch (n/1){
        default: note1 = n/1;
                 n = n-note1;
                 break;
    }

    cout<<"100 rupees note: "<<note100<<endl;
    cout<<"50 rupees note: "<<note50<<endl;
    cout<<"20 rupees note: "<<note20<<endl;
    cout<<"1 rupee note: "<<note1<<endl;

} 