#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *ptr){
    if(ptr->top==-1)
    {
        return 1;
    }
    return 0;
}
int isFull(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    return 0;
}
void push(int val,struct stack *ptr){
if(isFull(ptr)){
        printf("stack overflow\n");
        
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}
int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("stack underflow\n");
        return -1;
        
    }
    else{
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
        
    }
}
int peek(struct stack *sp,int i)
{
    int arrInd=sp->top-i+1;
    if(arrInd<0){
        printf("not a valid position for stack\n");
        return -1;
    }
    else{
        return sp->arr[arrInd];
    }
}
int main(){
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    s->size=7;
    s->top=-1;
    s->arr=(int*)malloc(s->size*sizeof(int));
    printf("before pushing elements stack is:%d\n",isFull(s));
    printf("before pushing elements stack is:%d\n",isEmpty(s));
    push(23,s);
    push(45,s);
    push(67,s);
    push(89,s);
    push(12,s);
    push(34,s);
    push(56,s);
    

    printf("after pushing elements stack is:%d\n",isFull(s));
    printf("after pushing elements stack is:%d\n",isEmpty(s));

    printf("popped element is %d\n",pop(s));
    printf("popped element is %d\n",pop(s));

    for(int j=1;j<=s->top+1;j++){
        printf("the value at position %d id %d\n",j,peek(s,j));
    }
    return 0;

    
    

}