#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void createll(node *&head,int data){
    struct node *ptr,*ptr1;
    if(head==NULL){
        ptr=(struct node*)malloc(sizeof(struct node));
        ptr->data=data;
        head=ptr;
        return;
    }
    struct node *tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    ptr1=(struct node*)malloc(sizeof(struct node));
    ptr1->data=data;
    tail->next=ptr1;
    return;
}
void printll(node *head){
    while(head!=NULL){
        printf("%d\n",head->data);
        head=head->next;
    }
    return;
}

int main() {
    struct node *head=NULL;
    createll(head,4);
    createll(head,5);
    createll(head,6);
    createll(head,7);
    printll(head);
    return 0;
}
