#include<bits/stdc++.h>
using namespace std;
int bitonic(int arr[],int n){
    int max;
    int dec[n],inc[n];
    dec[n-1]=1;
    inc[0]=1;
    for(int i=1;i<n;i++){
        if(arr[i-1]<arr[i]){
            inc[i]=inc[i-1]+1;
        }
        else{
            inc[i]=inc[i-1]+0;
        }
    }
    for(int u=n-2;u>=0;u--){
        if(arr[u+1]<arr[u]){
            dec[u]=dec[u+1]+1;
        }
        else{
            dec[u]=dec[u+1]+0;
        }
    }
    max=(inc[0]+dec[0])-1;
    for(int i=1;i<n;i++){
        if(inc[i]+dec[i]-1>max){
            max=inc[i]+dec[i]-1;
        }
    }
    return max;
}
int main(){
    int n,arr[10000];
    cin>>n;
    for(int t=0;t<n;t++){
        cin>>arr[t];
    }
    cout<<bitonic(arr,n)<<endl;
    return 0;
}
