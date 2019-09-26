#include<bits/stdc++.h>
using namespace std;
void reverserec(int start,int n,int arr[]){
    if(start>=n){
        return;
    }
    int temp=arr[start];
    arr[start]=arr[n];
    arr[n]=temp;
    return reverserec(start+1,n-1,arr);

}
void reversek(int n,int k,int arr[]){

    for(int i=0;i<n;i+=k){
        int j=(i+k-1);
        if(j<n){
        reverserec(i,j,arr);}
        else{
            reverserec(i,n-1,arr);
        }
    }
    return;
}
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    int arr[10000];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    reversek(n,k,arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
