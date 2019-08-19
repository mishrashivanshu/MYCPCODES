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
            return ;
        }
        node *tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        tail->next=new node(data);
        return;
    }
    void print(node *head){
        while(head!=NULL){
            cout<<head->data<<"-->";
            head=head->next;
        }
        return;
    }
    void insertathead(node *&head,int data){
        node *n=new node(data);
        n->next=head;
        head=n;
        return;
    }
    void insertatmiddle(node *&head,int p,int data){
        node *n=new node(data);
        node *temp=head;
        for(int i=0;i<p-1;i++){
            temp=temp->next;
        }
        n->next=temp->next;
        temp->next=n;
        return;
    }
int main(){
    node *head=NULL;
    insertattail(head,4);
    insertattail(head,5);
    insertattail(head,6);
    insertattail(head,7);
    insertattail(head,8);
    insertathead(head,2);
    insertathead(head,3);
    insertatmiddle(head,2,49);
    print(head);
    return 0;
}
