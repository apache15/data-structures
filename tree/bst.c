#include <stdio.h>
#include <stdlib.h>

struct Node{
    int key;struct Node *left, *right;
};
void inorder(struct Node* node){
    if(node != NULL){
        inorder(node->left);
        printf("%d ", node->key);
        inorder(node->right);
    }
}
struct Node *newNode(int key){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node *insert(struct Node *node, int key){
    if (node == NULL) return newNode(key);
    if(key < node->key) node->left = insert(node->left, key);
    else node->right = insert(node->right, key);
    return node;
}
void menu();
void main(){
    int key, chc; struct Node *root = NULL;
    do{
        menu(); scanf("%d", &chc);
        switch (chc) {
            case 1: printf("Element: ");scanf("%d", &key); root = insert(root, key); break;
            case 4: printf("TREE ->\t"); inorder(root);printf("\n"); break;
            case 0: printf("Bye\n");exit(0); break;
            default: printf("invalid choice.\n"); break;
        }
    } while (chc != 0);
}
void menu(){printf("===========================================\n1. insert\t\t5. delete\n2. insert last\t\t6. delete last\n3. insert specific\t7. delete specific\n4. display\t\t0. quit\nChoice : ");}