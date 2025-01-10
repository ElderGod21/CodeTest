#include <iostream>
using namespace std;

int pivot(int arr[],int n){
    //for the pivot
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
    return mid;
}

int elementIndex(int arr[],int n,int key, int p){
    int s = 0, e = n-1;
    int mid = s + (e-s)/2;

    if(arr[0]<=key){
        e=p-1;
        mid = s + (e-s)/2;
        while(s<=e){
            if(arr[mid]==key){
                return mid;
            }
            else if(arr[mid]<key){
                s=mid+1;
            }
            else if(arr[mid]>key){
                e=mid-1;
            }
            mid=s+(e-s)/2;
            
        }
        return -1;
    }
    else{
        s=p;
        mid= s+(e-s)/2;
        while(s<=e){
            if(arr[mid]==key){
                return mid;
            }
            else if(arr[mid]<key){
                s=mid+1;
            }
            else if(arr[mid]>key){
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return -1;
    }

}
int main(){
    int arr[5]={12,15,18,2,3};
    int p=pivot(arr,5);
    cout<<"Element index is: "<<elementIndex(arr,5,0,p);
}