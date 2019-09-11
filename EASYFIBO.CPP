#include<bits/stdc++.h>
using namespace std;
void fibo(long long int n){
  long long int curr,next,prev;
  long long int stor;
  for(long long int i=0;i<n;i++){
    if(i==0){
      prev=0;
      stor=0;
    }
    else if(i==1){
      next=1;
      stor=1%10;
    }
    else{
      curr=prev+next;
      if(i%2!=0){
        stor=curr%10;
      }
      prev=next;
      next=curr;
    }
    if(i+2>n||i==n){
      cout<<stor<<endl;
      return;
    }
  }
  return;
}
int main(){
  long long int n;
  cin>>n;
  while(n--){
    long long int t;
    cin>>t;
    fibo(t);
  }
  return 0;
}
