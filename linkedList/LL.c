#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *head = NULL;

void insertFirst(int elm){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (head == NULL){
        ptr->data = elm;
        ptr->next = NULL;
        head = ptr;
    }
    else{
        ptr->data = elm;
        ptr->next = head;
        head = ptr;
    }
}
void insertLast(int elm){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (head == NULL){
        ptr->data = elm;
        ptr->next = NULL;
        head = ptr;
    }
    else{
        struct Node *temp;
        temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        ptr->data = elm;
        ptr->next = NULL;
        temp->next = ptr;
    }
}
void insertSpecific(int index, int elm){
    if (head == NULL) {
        printf("Empty List");
    }else{
        struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
        struct Node *temp;
        temp = head;
        for (int i = 0; i < index-1; ++i){
            temp = temp->next;
        }
        ptr->data = elm;
        ptr->next = temp->next;
        temp->next = ptr;
    }
};
void deleteFirst(){
    if(head == NULL) printf("Empty List");
    else{
        struct Node *temp;
        temp = head;
        head = temp->next;
        free(temp);
    }
}
void deleteLast(){
    if(head == NULL) printf("Empty List");
    else{
        struct Node *temp;
        temp = head;
        while (temp->next->next != NULL){
            temp = temp->next;
        }
        temp->next = NULL;
        free(temp->next);
    }
}
void deleteSpecific(int elm){
    if(head == NULL)
        printf("Empty List");
    else{
        struct Node *temp, *temp2;
        temp = head;
        while (temp->next->data != elm) {
            temp = temp->next;
        }
        temp2 = temp->next;
        temp->next = temp->next->next;
        
        free(temp2);
    }
}
void show();void menu();
void main() {
    int chc, index, data;
    do{
        menu();
        scanf("%d", &chc);
        switch (chc) {
            case 1:printf("Element: ");scanf("%d", &data);insertFirst(data);break;
            case 2:printf("Element: ");scanf("%d", &data);insertLast(data);break;
            case 3:printf("Index: ");scanf("%d", &index);printf("Element: ");scanf("%d", &data);insertSpecific(index, data);break;
            case 5:deleteFirst();break;
            case 6:deleteLast();break;
            case 7:printf("Element: ");scanf("%d", &data);deleteSpecific(data);break;
            case 4:show();printf("\n");break;
            case 0: printf("Bye\n");exit(0);break;
            default: printf("invalid choice.\n");break;
        }
    }while (chc != 0);
    
    printf("\n");
}
void show(){
    struct Node *temp;
    if (head == NULL)
        printf("Empty List");
    else{
        temp = head;
        while (temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}
void menu(){
    printf("===========================================\n");
    printf("\n1. insert first");
    printf("\t\t5. delete first");
    printf("\n2. insert last");
    printf("\t\t6. delete last");
    printf("\n3. insert specific");
    printf("\t7. delete specific");
    printf("\n4. display");
    printf("\t\t0. quit");
    printf("\nChoice : ");
}