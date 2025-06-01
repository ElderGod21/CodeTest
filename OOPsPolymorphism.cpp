#include<iostream>
using namespace std;

class A{
    public:
    void sayHello(){
        cout<<"Hello "<<endl;
    }

    //can work with same name but input parameter should be changed or added

    void sayHello(string name){
        cout<<"Hello "<<name<<endl;
    }

    // void sayHello(string h){ 
    //     cout<<"Hello "<<h<<endl;
    // } 
    // didnt work because have to have different ya different type of input parameters 

};
int main(){

    A obj;
    obj.sayHello("papa");

}