#include <stdio.h>
#include <stdlib.h>

void CreateHeap(int A[], int size);
void Insert(int A[], int index);
int Delete(int A[], int size);
void HeapSort(int A[], int size);
void DisplayHeap(int A[], int size);
void Heapify(); // Left to Implement....

int main(){
    int A[10] = {0, 10, 19, 40, 5, 25, 6, 77, 90, 15};  // Keep 1st element in Array as 0..
    CreateHeap(A, 10);
    //Delete(A, 10);
    //Delete(A, 9);
    HeapSort(A, 10);
    DisplayHeap(A, 10);
}

void CreateHeap(int A[], int size){
    for(int i = 2; i < size; i++){
        Insert(A, i);
    }
}

void Insert(int A[], int index){
    int temp, i = index;
    temp = A[index];
    while(i > 1 && A[i/2] < temp){
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = temp;
}

int Delete(int A[], int n){
    int x, i, j;

    x = A[1];
    A[1] = A[n-1];
    i = 1, j = 2*i;

    while(j < n-1){
        if(A[j+1] > A[j]){
            j = j+1;
        }
        if(A[i] < A[j]){
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2*j;
        }
        else{
            break;
        }
    }
    A[n-1] = x;
}

void HeapSort(int A[], int size){
    for(int i = size-1; i > 1; i--){
        Delete(A, i);
    }
}

void DisplayHeap(int A[], int size){
    for(int i = 1; i < size; i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}
