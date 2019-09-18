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
node *buildTree(){
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
void preorder(node *root){
  if(root==NULL){
    return;
  }
  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
  return;
}
void printIn(node *root){
  if(root==NULL){
    return;
  }
  printIn(root->left);
  cout<<root->data<<" ";
  printIn(root->right);
  return;
}
int height(node *root){
  if(root==NULL){
    return 0;
  }
  int ls=height(root->left);
  int rs=height(root->right);
  return max(ls,rs)+1;
}
void printpost(node *root){
  if(root==NULL){
    return ;
  }
  printpost(root->left);
  printpost(root->right);
  cout<<root->data<<" ";
  return;
}
//8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
int main(){
  node *root=buildTree();
  preorder(root);
  cout<<endl;
  printIn(root);
  cout<<endl;
  printpost(root);
  cout<<endl;
  cout<<height(root);
  return 0;
}
