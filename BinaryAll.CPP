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
void printpost(node *root){
  if(root==NULL){
    return ;
  }
  printpost(root->left);
  printpost(root->right);
  cout<<root->data<<" ";
  return;
}
int main(){
  node *root=buildTree();
  preorder(root);
  cout<<endl;
  printIn(root);
  cout<<endl;
  printpost(root);
  return 0;
}
