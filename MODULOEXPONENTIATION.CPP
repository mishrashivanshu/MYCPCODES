#include<bits/stdc++.h>
#define ul unsigned long long int
using namespace std;
int power(int a, ul b,ul c){
  if(b==0){
    return 1;
  }
  int res=1;
  while(b>0){
    if(b&1){
      res=(res*a)%c;
    }
    a=(a*a)%c;
    b=b>>1;
  }
  return res;
}
int main(){
  cout<<(power(2,65,100)-1)%100;
  cout<<endl;
  return 0;

}
