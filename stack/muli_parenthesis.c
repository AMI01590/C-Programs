#include<stdio.h>
#include<stdlib.h>

struct stack {
    int size;
    int top;
    char *arr;
};
char isEmpty(struct stack *ptr){
    if(ptr->top==-1)
    {
        return 1;
    }
    return 0;
}
char isFull(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    return 0;
}
void push(char val,struct stack *ptr){
if(isFull(ptr)){
        printf("stack overflow\n");
        
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}
char pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("stack underflow\n");
        return -1;
        
    }
    else{
        char val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
        
    }
}

int parenthesisMatch(char *exp){
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    if (!sp) return 0;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));


    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
           push(exp[i], sp);
        }
        else if (exp[i] == ')'|| exp[i] == '}' || exp[i] == ']') {
            if (isEmpty(sp)) {
                return 0;
            }
            char popped_ch=pop(sp);
            if((exp[i]==')' && popped_ch!='(') || (exp[i]=='}' && popped_ch!='{') || (exp[i]==']' && popped_ch!='[')){
                free(sp->arr);
                free(sp);
                return 0;
            }
        }
    }
    int result = isEmpty(sp) ? 1 : 0;
    free(sp->arr);
    free(sp);
    return result;
}
int main(){
    char *exp = "[9+9]}*{0-7";
    if (parenthesisMatch(exp)) {
        printf("The parentheses are balanced.\n");
    } else {
        printf("The parentheses are not balanced.\n");
    }
    return 0;
}