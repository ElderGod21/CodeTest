#include<iostream>
using namespace std;


int main(){
   int n;
    cout<<"Enter the square grid no.- ";
    cin>>n;
    cout<<endl;
    for(int k=1; k<=n; k++){
      if(k<n/2){
        if(n%4==0){
         int i=1;
         while(i<=n/4){
             cout<<"->";
             i++;
           }
         int j=n/4 + 1;
           while(j<=3*n/2){
             cout<<"v|v";
             j++;
            }
         int l=3*n/4 + 1;
         while(l<=n){
            cout<<"<-";
            l++;
         }
         cout<<endl;
        }else{
         int i=1;
         while(i<=(n+1)/4){
             cout<<"->";
             i++;
           }
         int j=n/4 + 1;
           while(j<=3*n/2){
             cout<<"v|v";
             j++;
            }
         int l=3*n/4 + 1;
         while(l<=n){
            cout<<"<-";
            l++;
         }
         cout<<endl;

        }

      }
      if(k>=n/2){

       if(n%4==0){
         int i=1;
         while(i<=n/4){
             cout<<"->";
             i++;
           }
         int j=n/4 + 1;
           while(j<=3*n/2){
             cout<<"^|^";
             j++;
            }
         int l=3*n/4 + 1;
         while(l<=n){
            cout<<"<-";
            l++;
         }
         cout<<endl;
        }
      }
}
}
