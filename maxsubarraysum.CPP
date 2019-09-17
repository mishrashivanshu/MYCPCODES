#include<bits/stdc++.h>
using namespace std;
int kadane(int arr[],int n){
  int cs=0;
  int ms=0;
  for(int i=0;i<n;i++){
    cs+=arr[i];
    if(cs<0){
      cs=0;
    }
    ms=max(cs,ms);
  }
  return ms;
}
int main(){
  int n;
  cin>>n;
  int arr[100];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
      for(int k=i;k<=j;k++){
        cout<<arr[k]<<" ";
      }
      cout<<endl;
    }
  }
  cout<<"THE MAXIMUM SUB ARRAY SUM CALCULATED BY KADANE'S ALGO IS:\n";
  cout<<kadane(arr,n)<<endl;
  return 0;
}
