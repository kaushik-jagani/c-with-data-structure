#include"bits/stdc++.h"
using namespace std;

int main(){

    int n,k;
    cin>>n>>k;

    int arr[n][k];
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cin>>arr[i][j];
        }
        cout<<endl;
    }

      for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

}