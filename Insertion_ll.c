#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;

};
void traverseLinkedList(struct Node *ptr){
    while(ptr!=NULL){
        printf("element:%d\n", ptr->data);
        ptr= ptr->next;
    }
}
struct Node *insertAtBegining(struct Node *head, int data){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=head;
    head=ptr;
    return head;
}
struct Node *insertInBetween(struct Node *head,int data,int index){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node *p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}
struct Node *insertAtEnd(struct Node *head,int data){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node *p=head;
    while(p->next!=NULL){
        p=p->next;


    }
    
    p->next=ptr;
    ptr->next=NULL;
    return head;
}
struct Node *insertAfterNode(struct Node *head,struct Node *prevNode,int data){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=prevNode->next;
    prevNode->next=ptr;
    return head;
}
int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    head->data=7;
    head->next=second;
    second->data=54;
    second->next=third;
    third->data=199;
    third->next=NULL;
    printf("Linked list before insertion\n");
    traverseLinkedList(head);
    //head=insertAtBegining(head,72);
    //head=insertInBetween(head,100,2);
    //head=insertAtEnd(head,250);
    head=insertAfterNode(head,second,10045);
    printf("Linked list after insertion\n");
    traverseLinkedList(head);
    return 0;


}