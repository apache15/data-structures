#include <stdio.h>

void swap(int *x, int *y){*x = *x + * y;*y = *x - * y;*x = *x - * y;}
void printArray(int arr[], short size, char text[]){printf("%s\t", text);for(int i = 0; i < size; i++) printf("%d ", arr[i]);printf("\n");}

void bubbleSort(int arr[], int size){
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size-i-1; j++)
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

void main(){
	int arr[] = {6,5,5,95,61,66,51,6,98};
	bubbleSort(arr, 9);
	printArray(arr, 9, "Sorted ");
}
