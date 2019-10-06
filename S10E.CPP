#include<bits/stdc++.h>
using namespace std;
bool check(int i,int arr[]){
  if(i>5){
    int j=i-1,count1=1;
    while(count1<=5){
      if(arr[i]>=arr[j]){
        return false;
      }
      j--;
      count1++;
    }
    return true;
  }
  else{
    for(int j=i-1;j>=0;j--){
      if(arr[i]>=arr[j]){
        return false;
      }
    }
    return true;
  }
}
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,countx=0;
    cin>>n;
    int arr[200];
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    for(int i=1;i<n;i++){
      if(check(i,arr)){
        countx++;
      }
    }
    cout<<countx+1<<endl;
  }
  return 0;
}
