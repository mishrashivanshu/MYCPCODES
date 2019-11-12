#include<bits/stdc++.h>
using namespace std;
bool equal(int arr1[],int arr2[],int n){
    set<int> s;
    for(int i=0;i<n;i++){
        if(s.find(arr1[i])==s.end()){
            s.insert(arr1[i]);
        }
    }
    for(int i=0;i<n;i++){
        if(s.find(arr2[i])==s.end()){
            return false;
        }
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr1[1000000];
        int arr2[1000000];
        for(int i=0;i<n;i++){
            cin>>arr1[i];
        }
        for(int i=0;i<n;i++){
            cin>>arr2[i];
        }
        cout<<equal(arr1,arr2,n)<<endl;
    }
    return 0;
}
