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
void createll(node *&head,int data){
    if(head==NULL){
        head=new node(data);
        return;
    }
    node *tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    node *n=new node(data);
    tail->next=n;
    n->next=NULL;
    return;
}
void printll(node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    return;
}
node * findAtPositionK(node * head,int k){
    while(k-- && head){
        head = head->next;
    }
    return head;
}
int length(node * head){
    int k=0;
    while(head){
        head = head->next;
        k++;
    }
    return k;
}
void swap(node *& head, int i,int j){
    if(i==0 && j==1){
        node * a = head;
        node * b = head->next;
        node * bNext = b->next;
        head = b;
        b->next = a;
        a->next = bNext;
        return;
    }
    if(i==0){
        node * prev = findAtPositionK(head,j-1);
        node * a = head;
        node * b = prev->next;
        node * bNext = b->next;
        head = b;
        b->next = a->next;
        prev->next = a;
        a->next = bNext;
        return;
    }
    if(j-i==1){
        node * prev = findAtPositionK(head,i-1);
        node * a = prev->next;
        node * b = a->next;
        node * bNext = b->next;
        prev->next = b;
        b->next = a;
        a->next = bNext;
        return;
    }
    node * prev1 = findAtPositionK(head,i-1);
    node * prev2 = findAtPositionK(head,j-1);
    node * a = prev1->next;
    node * b = prev2->next;
    node * bNext = b->next;
    prev1->next = b;
    b->next = a->next;
    prev2->next = a;
    a->next = bNext;
    return;
}
void bubbleSort(node ** head){
    int n = length(*head);
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            node * a = findAtPositionK(*head,j);
            node * b = findAtPositionK(*head,j+1);
            if(a->data > b->data){
                swap(*head,j,j+1);
            }
        }
    }
    return;
}

int main(){
    node *head=NULL;
    createll(head,6);
    createll(head,400);
    createll(head,52);
    createll(head,1);
    bubbleSort(&head);
    printll(head);
    return 0;
}
