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
void reversesubparts(node *head){
    node *temp=head;
    while(temp!=NULL&&temp->next!=NULL){
        if((temp->data)%2==0&&(temp->next->data)%2==0){
            swap(temp->data,temp->next->data);
            temp=temp->next->next;
        }
        else{
            temp=temp->next;
        }
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
/*void kreverse(node *&head,int k){
    node*temp =head;
    for(int )
}*/
void printll(node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    return;
}
int main(){
    node *head=NULL;
    int n,t;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t;
        insertattail(head,t);        
    }
    //reversesubparts(head);
    head=reverserec(head);
    printll(head);
    return 0;

}
