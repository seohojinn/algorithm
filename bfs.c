#include <stdio.h>

int front;
int back=1;
int N,M,V;
int adj[1000][10000];

int f(int * check_arr,int i){
    for(int j=0;j<back;j++){
        if(i==check_arr[j]){
            return 0;
        }
    }
    return 1;
}

void push_pop(int * queue,int * check_arr){
    queue[0]=V;
    check_arr[0]=V;
    while(back>front){
        for(int i=0;i<N;i++){
            if(adj[queue[front]-1][i]==1 && f(check_arr,i+1)){
                queue[back]=i+1;
                check_arr[back]=i+1;
                back++;
            }
        }
        front++;
    }
}

int main(){

    int queue[100]={1,};
    int check_arr[100]={1,};
    int a=0,b=0;

    scanf("%d %d %d",&N,&M,&V);

    for(int i=0;i<M;i++){
        scanf("%d %d",&a,&b);
        adj[a-1][b-1]=1;
        adj[b-1][a-1]=1;
    }

    push_pop(queue,check_arr);

    for(int i=0;i<back;i++){
        printf("%d ",check_arr[i]);
    }
    puts("");

    return 0;
}