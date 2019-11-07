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
bool same(node *t,node *ts){
    if(t==NULL&&ts==NULL){
        return true;
    }
    if(t==NULL||ts==NULL){
        return false;
    }
    return (t->data==ts->data&&same(t->left,ts->left)&&same(t->right,ts->right));
}
bool ifsub(node *t,node *ts){
    if(ts==NULL){
        return true;
    }
    if(t==NULL){
        return false;
    }
    if(same(t,ts)){
        return true;
    }
    return (ifsub(t->left,ts))||(ifsub(t->right,ts));
}
int main(){
    cout<<"Enter the Tree 1:"<<endl;
    node *root1=buildTree();
    cout<<"Enter the subtree:"<<endl;
    node *root2=buildTree();
    if(ifsub(root1,root2)){cout<<"YES IT IS A SUBTREE"<<endl;}
    else{cout<<"NOT A SUBTREE!"<<endl;}
    return 0;
}
