#include<bits/stdc++.h>
using namespace std;
int main(){
  int arr[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
  int count1=0;
  int a=0;
  while(true){
    for(int i=a,j=a;j<4-a;j++){
      cout<<arr[i][j]<<" ";
      count1++;
      if(count1>=16){
        return 0;
      }
    }
    for(int i=a+1,j=3-a;i<4-a;i++){
      cout<<arr[i][j]<<" ";
      count1++;
      if(count1>=16){
        return 0;
      }
    }
    for(int j=2-a,i=3-a;j>=a;j--){
      cout<<arr[i][j]<<" ";
      count1++;
      if(count1>=16){
        return 0;
      }
    }
    for(int i=2-a,j=a;i>a;i--){
      cout<<arr[i][j]<<" ";
      count1++;
      if(count1>=16){
        return 0;
      }
    }
    a++;
  }
  cout<<endl;
  return 0;
}
