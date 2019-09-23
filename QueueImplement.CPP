#include<iostream>
using namespace std;
struct queue{
  int *arr;
  int f;
  int r;
  int ms;
  int cs;
  void createqueue(int ds){
    f=0;
    ms=ds;
    r=ms-1;
    arr=(int *)malloc(sizeof(int)*ms);
    cs=0;
    return;
  }
  bool isFull(){
    return cs==ms;
  }
  bool isEmpty(){
    return cs==0;
  }
  void push(int data){
    if(!isFull()){
      r=(r+1)%ms;
      arr[r]=data;
      cs++;
    }
  }
  void pop(){
    if(!isEmpty()){
      f=(f+1)%ms;
      cs--;
    }
  }
  int getFront(){
    return arr[f];
  }
};
int main(){
  queue q;
  q.createqueue(10);
  for(int i=1;i<=6;i++){
    q.push(i);
  }
  q.pop();
  while(!q.isEmpty()){
    cout<<q.getFront()<<" ";
    q.pop();
  }
  return 0;

}
