#include<bits/stdc++.h>
using namespace std;
struct node{
  int data;
  node *left;
  node *right;
  node(int data){
    this->data=data;
    left=NULL;
    right=NULL;
  }
};
node * buildTree(){
  int c;
  cin>>c;
  if(c==-1){
    return NULL;
  }
  node *root=new node(c);
  root->left=buildTree();
  root->right=buildTree();
  return root;
}
void printbt(node *root){
  if(root==NULL){
    return;
  }
  cout<<root->data<<" ";
  printbt(root->left);
  printbt(root->right);
  return ;
}

int main(){
  node *root=buildTree();
  printbt(root);
  return 0;
}
