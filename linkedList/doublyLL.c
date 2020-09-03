#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void insertFirst(int data){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->prev = NULL;
    node->next = head;
    head = node;
}

void insertLast(int data){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;

    struct Node *temp;
    temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    node->prev = temp;
    temp->next = node;
}
void insertSpecific(int loc, int data){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    if(head == NULL){
        node->next = NULL;
        node->prev = NULL;
        head = node;
    }
    else{
        struct Node *temp;
        temp = head;
        for(int i = 0; i <= loc; ++i){
            temp = temp->next;
        }
        temp->next->prev = node;
        node->prev = temp;
        node->next = temp->next;
        temp->next = node;
    }
}
void deleteFirst(){
    if(head == NULL){
        printf("Empty List\n");
    }
    else if(head->next == NULL){
        head->next = head->prev = NULL;
        head = NULL;
        free(head);
    }
    else{
        struct Node *temp;
        temp = head;
        head = temp->next;
        head->prev = temp->next = NULL;
        free(temp);
    }
}
void deleteLast(){
    if(head == NULL){printf("Empty List\n");}
    else{
        struct Node *temp;
        temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
    }    
}
void deleteSpecific(int data){
    struct Node *temp;
    if(head->data == data){
        temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        free(temp);
    }else{
        temp = head;
        while (temp->data != data){
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);    
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
void menu(){printf("===========================================\n\n1. insert first\t\t5. delete first\n2. insert last\t\t6. delete last\n3. insert specific\t7. delete specific\n4. display\t\t0. quit\nChoice : ");}