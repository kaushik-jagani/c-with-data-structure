#include<bitset>
#include<iostream>
using namespace std;


int linearsearch(int arr[],int n, int key){
for(int i=0;i<n;i++){
    if(arr[i]==key){
        return i;
    }
}
return -1;
}

int main(){
    int n;

   cout <<"enter a size of array:-->";
    cin>>n;

    int arr[n];

cout <<"enter a element of array:-->";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int key;

    cout<<"enter a key which u find:-->";
    cin>>key;

    cout<<linearsearch(arr,n,key)<<endl;

}