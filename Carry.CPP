#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
    node(int data){
        this->data=data;
        next=NULL;
    }
};
void insertattail(node *&head,int data){
    if(head==NULL){
        head=new node(data);
        return;
    }
    node *n=new node(data);
    node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->next=NULL;
    return ;
}
void print(node *head){
  while(head!=NULL){
    cout<<head->data;
    head=head->next;
  }
  return;
}
node * reverserec(node *head){
    if(head->next==NULL||head==NULL){
        return head;
    }
    node *smallhead=reverserec(head->next);
    node *Current=head;
    Current->next->next=Current;
    Current->next=NULL;
    return smallhead;
}
node * printreq(node *head){
    node *k=head,*t;
    int carry=1;
    int sum;
    while(head!=NULL){
        sum=head->data+carry;
        if(sum>=10){
        carry=1;}
        else{
          carry=0;
        }
        sum=sum%10;
        head->data=sum;
        t=head;
        head=head->next;
    }
    if(carry>0){
      node *n=new node(carry);
      t->next=n;
    }

    return k;
}
int main(){
    node *head=NULL;
    int n,t;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t;
        insertattail(head,t);
    }
    head=reverserec(head);
    head=printreq(head);
    head=reverserec(head);
    print(head);
    return 0;

}
