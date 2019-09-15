#include<bits/stdc++.h>
using namespace std;
int main(){
  int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};

  for(int i=0;i<3;i++){
    for(int h=0;h<i;h++){
      swap(arr[i][h],arr[h][i]);
    }
  }
  for(int t=0;t<3;t++){
    for(int y=2;y>=0;y--){
      cout<<arr[t][y]<<" ";
    }
    cout<<endl;
  }

  return 0;
}
