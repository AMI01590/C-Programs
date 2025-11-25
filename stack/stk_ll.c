#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct stack{
    struct node *top;
};
int isEmpty(struct stack *s){
    if(s->top==NULL){
        return 1;
    }
    return 0;
}
int isFull(struct stack *s){
    struct node *p=(struct node*)malloc(sizeof(struct node));
    if(p==NULL){
        return 1;
    }
    return 0;

}
void push(struct node *top,int val,struct stack *s){
    if(isFull(s)){
        printf("stack overflow\n");

    }
    else{
        struct node *n=(struct node *)malloc(sizeof(struct node));
        n->data=val;
        n->next=top;
        s->top=n;
    }
}
int pop(struct stack *s){
    if(isEmpty(s)){
        printf("stack underflow\n");

    }
    else{
        struct node *n=s->top;
        s->top=s->top->next;
        int x=n->data;
        printf("the popped element is %d\n",x);
        free(n);
    }
}
int peek(struct stack *s,int i){
    struct node *ptr=s->top;
    for(int j=0;j<i-1 && ptr!=NULL;j++){
        ptr=ptr->next;

    }
    if(ptr!=NULL){
        return ptr->data;

    }
    else{
        return -1;
    }
}
int stackTop(struct stack *s){
    if(!isEmpty(s)){
        return s->top->data;
    }
    return -1;
}
int stackBottom(struct stack *s){
    struct node *ptr=s->top;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    return ptr->data;
}
int main(){
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    s->top=NULL;
    push(s->top,10,s);
    push(s->top,20,s);
    push(s->top,30,s);
    push(s->top,40,s);

    for(int i=1;i<=4;i++){
        printf("the value at position %d is %d\n",i,peek(s,i));
    }
    pop(s);
    printf("after popping the element the new top is %d\n",peek(s,1));
    printf("the top element is %d\n",stackTop(s));
    printf("the bottom element is %d\n",stackBottom(s));
}