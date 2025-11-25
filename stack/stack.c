#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *s){
    if(s->top==-1){
        return 1; //true
    }
    else{
        return 0; //false
    }
}
int isFull(struct stack *s){
    if(s->top==s->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    struct stack *s;
    s->size=6;
    s->top=-1;
    s->arr=(int*)malloc(s->size*sizeof(int));
    printf("enter the elements of stack:\n");
    for(int i=0;i<s->size;i++){
        scanf("%d",&s->arr[i]);
        s->top++;
    }
    if(isEmpty(s)){
        printf("Stack is empty\n");
    }
    else{
        printf("Stack is not empty\n");
    }



}