#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void traverseLinkedList(struct Node *ptr)
{
    while(ptr!=NULL){
        printf("elements:%d\n",ptr->data);
        ptr=ptr->next;
    }
}
struct Node  *deletionAtBegining(struct Node *head){
    struct Node *q=head;
    head=head->next;
    free(q);
    return head;
   
}
struct Node *deletionAtIndex(struct Node *head,int index){
    struct Node *p=head;
    struct Node *q=head->next;
    for(int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;
        
    }
    p->next=q->next;
    free(q);
    return head;
}
struct Node *deletionAtEnd(struct Node *head){
    struct Node *ptr=head;
    struct Node *qtr=head->next;
    while(qtr->next!=NULL){
        ptr=ptr->next;
        qtr=qtr->next;
    }
    ptr->next=NULL;
    free(qtr);
    return head;
}
struct Node *deletionByValue(struct Node *head,int value){
    struct Node *p=head;
    struct Node *q=head->next;
    while(q->data!=value && q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    if(q->data==value){
        p->next=q->next;
        free(q);
    }
    return head;
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));

    head->data=7;
    head->next=second;
    second->data=11;
    second->next=third;
    third->data=66;
    third->next=fourth;
    fourth->data=88;
    fourth->next=NULL;
    printf("linked list before deletion\n");
    traverseLinkedList(head);
    printf("linked list after deletion\n");
    //head=deletionAtBegining(head);
    //head=deletionAtIndex(head,3);
    //head=deletionAtEnd(head);
    head=deletionByValue(head,1);
    traverseLinkedList(head);

}
