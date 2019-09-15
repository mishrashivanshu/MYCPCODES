#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  long long int arr[1000000];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  long long int min1=arr[0];
  long long int max1=arr[0];
  long long int count1=0;
  long long int count2=0;
  for(int i=1;i<n;i++){
    if(arr[i]>max1){
      count1++;
      max1=arr[i];
    }
    else if(arr[i]<min1){
      count2++;
      min1=arr[i];
    }
  }
  cout<<count1<<" "<<count2<<endl;
  return 0;
}
