#include <stdio.h>
#define SIZE 5

int stack[SIZE], top = -1;

int isFull(){
    return (top >= SIZE-1) ? 1 : 0;
}
int isEmpty(){
    return (top == -1) ? 1 : 0;
}
void push(){
    int elm;
    printf("Element\t: ");
    scanf("%d", &elm);
    if(!isFull())
        stack[++top] = elm;
}
void pop(){
    printf("Popped\t: %d", stack[top--]);
}
void peak(){
    printf("Peak\t: %d", stack[top]);
}
void traverse(){
    if(!isEmpty())
        printf("Stack\t: ");
        for(int i = 0; i <= top; i++)
            printf("%d ", stack[i]);
    
}
void main(){
    int ch;
    do{
        printf("\n[1] Push\t[2] Pop \t[3] Traverse\t[4] Peak\t[5] Quit\nChoice\t: "); scanf("%d", &ch);
        switch (ch){
            case 1: push(); break;
            case 2: pop();  break;
            case 3: traverse(); break;
            case 4: peak(); break;
            case 5: printf("Bye"); break;
            default: printf("Invalid Choice"); break;
        }
        printf("\n");
    }while(ch != 5);
}