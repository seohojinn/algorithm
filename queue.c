#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int point;
int f=-1;

int front(int * arr){
    if(point-1==f){
        return -1;
    }
    else{
        return arr[f+1];
    }
}

int back(int * arr){
    if(point-1==f){
        return -1;
    }
    else{
        return arr[point-1];
    }
}

int empty(){
    if(point-1==f){
        return 1;
    }
    else{
        return 0;
    }
}

int size(){
    return point-(f+1);
}

int pop(int * arr){
    if(f+1==point){
        return -1;
    }
    else{
        f++;
        return arr[f];

    }
}

void push(int * arr, int value){
    arr[point]=value;
    point++;
}

int main(){
    int N=0;
    char commend[10];
    int X=0;
    int *arr;
    memset(commend,'\0',sizeof(commend));
    scanf("%d",&N);
    arr=(int*)(malloc(sizeof(int)*N));
    for(int i=0;i<N;i++){
        scanf("%s",commend);
        if(!strcmp(commend,"push")){
            scanf("%d",&X);
            push(arr,X);
        }
        else if(!strcmp(commend,"pop")){
            printf("%d\n",pop(arr));
        }
        else if(!strcmp(commend,"size")){
            printf("%d\n",size());
        }
        else if(!strcmp(commend,"back")){
            printf("%d\n",back(arr));
        }
        else if(!strcmp(commend,"empty")){
            printf("%d\n",empty());
        }
        else if(!strcmp(commend,"front")){
            printf("%d\n",front(arr));
        }
        memset(commend,'\0',sizeof(commend));
    }
    free(arr);
    return 0;
}