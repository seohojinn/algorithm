#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int point;

int top(int * arr){
    if(point<=0){
        return -1;
    }
    else{
        return arr[point-1];
    }
}

int empty(){
    if(point<=0){
        return 1;
    }
    else{
        return 0;
    }
}

int size(){
    return point;
}

int pop(int * arr){
    if(point<=0){
        return -1;
    }
    else{
        point--;
        return arr[point];
    }
}

void push(int * arr, int value){
    arr[point]=value;
    point++;
}

int main(){
    int N=0;
    char commend[10];
    int pushvalue=0;
    int *arr;
    memset(commend,'\0',sizeof(commend));
    scanf("%d",&N);
    arr=(int*)(malloc(sizeof(int)*N));
    for(int i=0;i<N;i++){
        scanf("%s",commend);
        if(!strcmp(commend,"push")){
            scanf("%d",&pushvalue);
            push(arr,pushvalue);
        }
        else if(!strcmp(commend,"pop")){
            printf("%d\n",pop(arr));
        }
        else if(!strcmp(commend,"size")){
            printf("%d\n",size());
        }
        else if(!strcmp(commend,"empty")){
            printf("%d\n",empty());
        }
        else if(!strcmp(commend,"top")){
            printf("%d\n",top(arr));
        }
        memset(commend,'\0',sizeof(commend));
    }
    free(arr);
    return 0;
}
