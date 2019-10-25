#include<bits/stdc++.h>
using namespace std;
unsigned int getpos(int n){
  return log2(n & -n)+1;
}
int main(){
  int n;
  cin>>n;
  cout<<getpos(n)<<endl;;
  return 0;
}
