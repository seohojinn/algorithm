#include <stdio.h>
#include <limits.h>


void swap(int * arr, int a, int b){
    int change=0;
    change=arr[a];
    arr[a]=arr[b];
    arr[b]=change;

}

void selection(int *arr, int size){
    int min=INT_MAX;
    int min_idx=0;
    for(int i=0;i<size-1;i++){
        min=INT_MAX;
        min_idx=i;
        for(int j=i;j<size;j++){
            if(min>arr[j]){
                min=arr[j];
                min_idx=j;
            }
            printf("idx : %d\n",min_idx);
        }
        swap(arr,i,min_idx);
        for(int a=0;a<size;a++){
            printf("%d ",arr[a]);
        }
        printf("\n");
    }

        
}




int main(){
    int arr[10];
    int size=0;
    scanf("%d",&size);
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    selection(arr,size);
    // for(int j=0;j<size;j++){
    //     printf("%d ",arr[j]);
    // }
    return 0;

}