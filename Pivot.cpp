#include <iostream>
#include <vector>
using namespace std;

int pivot(int arr[],int n){

    int s=0, e=n-1;
    int mid = s +(e-s)/2;

    while(s<e){
        if(arr[mid]>=arr[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid = s + (e-s)/2;
    }
    return mid;//or s or e
}


int main(){
    int arr[5]= {3,8,10,17,1};
    cout<<"Pivot is at: "<<pivot(arr,5);
}

