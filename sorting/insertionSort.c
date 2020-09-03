#include <stdio.h>

void swap(int *x, int *y){*x = *x + * y;*y = *x - * y;*x = *x - * y;}
void printArray(int arr[], short size, char text[]){printf("%s\t", text);for(int i = 0; i < size; i++) printf("%d ", arr[i]);printf("\n");}

void insertionSort(int arr[], int size){
    for(int i = 1; i < size; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = key;
    }
}

void main(){
    int arr[] = {2,54,13, 5, 84, 4,6,7, 45, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, size, "Before sort");
    insertionSort(arr, size);
    printArray(arr, size, "Insertion sort");
}