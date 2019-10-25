//PowerSet
#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int count=(1<<s.size());
  for(int count1=0;count1<count;count1++){
    for(int j=0;j<s.size();j++){
      if((count1&(1<<j))>0){
        cout<<s[j];
      }
      cout<<" ";
    }
    cout<<endl;
  }
  return 0;
}
