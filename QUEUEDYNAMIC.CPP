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
struct queue1{
    node *head=NULL;
    void push(int data){
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
    void pop(){
        if(head==NULL){
            return;
        }
        node *temp=head;
        head=head->next;
        cout<<temp->data<<endl;
        delete(temp);
    }
};
int main(){
    queue1 q;
    q.push(8);
    q.push(9);
    q.push(10);
    q.push(11);
    q.pop();
    q.pop();
    return 0;
}
