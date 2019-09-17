#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int arr[1000000];
  for(int i=3;i<=n;i+=2){
    arr[i]=1;
  }
  for(int i=3;i<=n;i+=2){
    if(arr[i]){
      for(int j=i*i;j<=n;j+=2*i){
        arr[j]=0;
      }
    }
  }
  for(int i=2;i<=n;i++){
    if(arr[i]==1){
      cout<<i<<" ";
    }
  }
  return 0;
}
