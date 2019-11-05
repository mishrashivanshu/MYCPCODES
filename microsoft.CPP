#include<bits/stdc++.h>
using namespace std;
void printsecondhalf(int n,int k){
    if(n==k){
        cout<<n<<" ";
        return;
    }
    cout<<n<<" ";
    printsecondhalf(n+4,k);
    return;
}
void printfirsthalf(int n,int k){
  if(n<=0){
    printsecondhalf(n,k);
    return;
  }
  cout<<n<<" ";
  printfirsthalf(n-4,k);
  return;
}
int main(){
  int n;
  cin>>n;
  printfirsthalf(n,n);
  cout<<endl;
  return 0;
}
