#include<iostream>
using namespace std;

int peakValue(int arr[], int n){
    for(int i= 0;i+2<n;i++){
        if(arr[i]<=arr[i+1] && arr[i+1]>=arr[i+2]){
            return arr[i+1];
        }
    }
    return -1;

}

int main(){
    int arr[10]= {0,2,3,4,5,10,20,5,4};
    cout<<peakValue(arr,10);
}