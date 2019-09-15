#include<bits/stdc++.h>
using namespace std;
int main(){
  char str[]="Hello Everyone This is Shivanshu Mishra";
  char *ptr;
  ptr=strtok(str," ");
  while(ptr!=NULL){
    cout<<ptr<<endl;
    ptr=strtok(NULL," ");
  }
  return 0;
}

