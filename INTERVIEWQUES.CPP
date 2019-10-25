//Given an Array that contains all elements even number of timesexcept two odd occuring numbers find those numbers.
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int arr[1000000];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int t=arr[0];
  for(int y=1;y<n;y++){
    t=t^arr[y];
  }
  cout<<t<<endl;
  return 0;
}
