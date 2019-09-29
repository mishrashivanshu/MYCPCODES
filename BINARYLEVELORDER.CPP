//g++ BINARYLEVELORDER.CPP
//1 2 4 11 -1 -1 -1 5 12 -1 -1 -1 3 6 8 -1 -1 9 -1 -1 7 -1 10 -1 -1
#include<bits/stdc++.h>
using namespace std;
struct node{
  int data;
  node*right;
  node *left;
  node(int data){
    this->data=data;
    left=NULL;
    right=NULL;
  }
};
node *buildtree(){
  int c;
  cin>>c;
  if(c==-1){
    return NULL;
  }
  node *x=new node(c);
  x->left=buildtree();
  x->right=buildtree();
  return x;
}
int height(node *root){
  if(root==NULL){
    return 0;
  }
  int ls=height(root->left);
  int rs=height(root->right);
  return max(ls,rs)+1;
}
void printlevel(node *root,int k){
  if(root==NULL){
    return;
  }
  if(k==1){
    cout<<root->data<<" ";
    return;
  }
  printlevel(root->left,k-1);
  printlevel(root->right,k-1);
  return;
}
int main(){
  node *root=buildtree();
  int h=height(root);
  for(int i=1;i<=h;i++){
    printlevel(root,i);
    cout<<endl;
  }
  return 0;
}
