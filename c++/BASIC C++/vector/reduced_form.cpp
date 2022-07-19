#include"bits/stdc++.h"
using namespace std;

bool compare(pair<int, int> p1,pair<int, int> p2){
    return p1.first<p2.first;
}
int main(){
    int arr[]={10,16,7,14,5,3,1};
    vector<pair<int,int>> v;
    for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++){
        v.push_back(make_pair(arr[i],i));   // pair of value,index
    }

    
    // for(int i=0;i<v.size();i++){
    // cout<<v[i];
    // } --> we dose not display pair using loop


    sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size();i++){
        arr[v[i].second]=i;
    }

    for(int i=0;i<v.size();i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

}