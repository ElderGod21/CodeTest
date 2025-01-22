#include <iostream>
using namespace std;

void rowWiseSum(int arr[][3],int row, int col){
    for(int i=0;i<row;i++){
        int ans =0;
        for(int j = 0;j<col;j++){
            ans+= arr[i][j];
        }
        cout<<ans<<" "<<endl;
    }
}

int main(){
    int arr[4][3];
    cout<<"Enter 12 values: "<<endl;

    for(int i =0;i<4;i++){
        for(int j = 0; j<3;j++){
            cin>>arr[i][j];
        }
    }

    rowWiseSum(arr,4,3);

}