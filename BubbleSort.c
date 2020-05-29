#include <stdio.h>

#define MAX_ARRAY_SIZE 100

void swap(int *,int,int);

void bubble_sort(int * arr, int size){
    for(int i=size-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr,j,j+1);
            }
        }
    }
}

// arr[a] <-> arr[b]
void swap(int * arr,int a,int b){
    int change=0;
    change=arr[a];
    arr[a]=arr[b];
    arr[b]=change;
}

int main(){
    int arr[MAX_ARRAY_SIZE];
    int size=0;
    scanf("%d",&size);
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    bubble_sort(arr,size);
    for(int j=0;j<size;j++){
        printf("%d ",arr[j]);
    }

    return 0;
}