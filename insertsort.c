#include <stdio.h>

void change(int *arr,int a, int key){

    for(int i=a;i>=0;i--){
        arr[i+1]=arr[i];
        if(i!=0){
            if(key>arr[i-1]){
                arr[i]=key;
                break;
            }
        }
        else if(i==0){
            arr[i]=key;
        }
    }
}

void insertion(int *arr, int size){
    int key=0;
    for(int i=0;i<size-1;i++){
        if(arr[i]>arr[i+1]){
            key=arr[i+1];
            change(arr,i,key);
        }
        // for(int j=0;j<size;j++){
        //     printf("%d ",arr[j]);
        // }
        // printf("\n");
    }
}

int main(){
    int arr[10];
    int size=0;
    scanf("%d",&size);
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    insertion(arr,size);
    
    for(int j=0;j<size;j++){
        printf("%d ",arr[j]);
    }
    puts(" ");
    return 0;

}