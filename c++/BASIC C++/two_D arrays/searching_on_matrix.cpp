#include<bits/stdc++.h>
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

    int search;
    cout<<"enter element to find"<<"\n";
    cin>>search;

      for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            if(arr[i][j]==search)
            {
                cout<<"element was found"<<"\t";
                cout<<i<<" "<<j<<" ";

            }
            else{
                 cout<<"element was not found"<<"\t";
            }
        }
        cout<<endl;
    }

}