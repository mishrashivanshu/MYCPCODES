//g++ DIIVDEANDCONQUERMAXSUBARRAY.CPP
#include<bits/stdc++.h>
using namespace std;
int maxcrossingsum(int arr[],int l,int h){
  int leftsum=INT_MIN;
  int sum=0;
  int mid=(l+h)/2;
  for(int i=mid;i>=l;i--){
    sum+=arr[i];
    if(sum>leftsum){
      leftsum=sum;
    }
  }
  int rightsum=INT_MIN;
  sum=0;
  for(int i=mid+1;i<=h;i++){
    sum+=arr[i];
    if(sum>rightsum){
      rightsum=sum;
    }
  }
  return leftsum+rightsum;
}
int maxsubarraysum(int arr[],int l,int h){
  if(h==l){
    return arr[h];
  }
  int mid=(l+h)/2;
  return max(max(maxsubarraysum(arr,l,mid),maxsubarraysum(arr,mid+1,h)),maxcrossingsum(arr,l,h));
}
int main(){
  int n;
  cin>>n;
  int arr[1000000];
  for(int t=0;t<n;t++){
    cin>>arr[t];
  }
  cout<<maxsubarraysum(arr,0,n-1)<<endl;
  return 0;
}
