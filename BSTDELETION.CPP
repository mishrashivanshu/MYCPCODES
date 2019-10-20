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
node *build(){
    int c;
    cin>>c;
    if(c==-1){
        return NULL;
    }
    node *n=new node(c);
    n->left=build();
    n->right=build();
    return n;
}
void inorder(node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return;
}
node *findmin(node *root){
    if(root==NULL){
        return NULL;
    }
    node *current=root;
    while(current->left!=NULL){
        current=current->left;
    }
    return current;
}
node *deletenode(node *root,int key){
    if(root==NULL){
        return root;
    }
    if(key<root->data){
        root->left=deletenode(root->left,key);
    }
    else if(key>root->data){
        root->right=deletenode(root->right,key);
    }
    else{
        if(root->left==NULL){
            node *temp=root->right;
            delete(root);
            return temp;
        }
        else if(root->right==NULL){
            node *temp=root->left;
            delete(root);
            return temp;
        }
        node *temp=findmin(root->right);
        root->data=temp->data;
        root->right=deletenode(root->right,temp->data);
    }
    return root;
}
int main(){
    node *root=build();
    inorder(root);
    cout<<endl;
    root=deletenode(root,20);
    inorder(root);
    return 0;
}
